##########################
## Description: Use selenium to scrape race results from a venue for a particular day and store in a csv file
## Python 3 environment
## Install selenium with webdriver [https://selenium-python.readthedocs.io/installation.html] 
# ######################## 

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.chrome.options import Options

import time
import csv

options = Options()
options.add_argument('--headless') # headless browser so GUI is not shown
options.add_argument('--incognito')
driver = webdriver.Chrome(options=options)
# driver = webdriver.Chrome()
filename = "New_data.csv"
open(filename,'w').close() #clear contents of the file

venue_count = 0

## TODO: insert your URL from neds website
venue_link = "https://www.neds.com.au/racing/crayford-bags/be08ef05-9b2b-4805-af32-1b42acbff4f6"
venue_count += 1
###########################################################
###### Get the links to all 12 races at a venue
###########################################################
venue_name = venue_link.split("/")[-2] # Get venue name from the url
venue_name = venue_name.replace('-','_')

# url = "https://www.neds.com.au/racing/central-park-bags/7567831f-f219-41ee-8a1c-cb2a1e03d451"
driver.get(venue_link)
time.sleep(2)
try:
    # Wait for 10 secs or until elementID "page-content" is loaded on the page
    elem = WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.ID, "page-content"))
    )
finally:
    data = elem.find_elements_by_class_name('race-switcher-list__link')
    race_links = []
    for race_link in data:
        # print(link.get_attribute('innerHTML'))
        # print(race_link.get_attribute('href'))
        race_links.append(race_link.get_attribute('href'))
print(f'...Downloaded race links from Venue{venue_count}: {venue_name} ')        
    
###########################################################
###### Operate on each link/race
###########################################################
# ranking/results (1st, 2nd, 3rd)
r1 = []
r2 = []
r3 = []
# Players/runners (6 players)
p1 = []
p2 = []
p3 = []
p4 = []
p5 = []
p6 = []


for url in race_links:
    driver.get(url)
    time.sleep(2)
    try:
        
        elem = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.ID, "page-content"))
        )
    finally:
        data = elem.text
        
    ## Divide up the data into two parts (rankings and players)
    flag_part2 = False 
    data_arr_part1 = [] 
    data_arr_part2 = []
    abdn_flag = False
    ## Check through the scrated text data
    for line in data.splitlines():
        if(line == 'Abandoned'):
            abdn_flag = True
            break

        if not flag_part2:
            data_arr_part1.append(str(''.join(line)))
        if(line == 'RUNNERS' or flag_part2 == True):
            flag_part2 = True
            data_arr_part2.append(str(''.join(line)))
        # print(line)

    # print(data_arr_part1)
    # print("end of part1")
    # print(data_arr_part2)

    # check if the race is abandoned
    if not abdn_flag:
        ## Counters to account for multiple 1st, 2nd or 3rd positions
        count_1st = 0
        count_2nd = 0
        count_3rd = 0

        ## Add data for Top 3 ranks' odds
        for i,val in enumerate(data_arr_part1):
            if(val == '1st'):
                count_1st += 1
                if(count_1st == 3):
                    r3.append(str(data_arr_part1[i+1][0])) #get the first value of that string
                elif(count_1st == 2):
                    r2.append(str(data_arr_part1[i+1][0]))
                else:
                    r1.append(str(data_arr_part1[i+1][0])) 
            elif(val == '2nd'):
                count_2nd += 1
                if(count_2nd == 2):
                    r3.append(str(data_arr_part1[i+1][0])) #get the first value of that string
                else:
                    r2.append(str(data_arr_part1[i+1][0]))
            elif(val == '3rd'):
                count_3rd += 1
                if(count_1st + count_2nd < 3 and count_3rd == 1):
                    r3.append(str(data_arr_part1[i+1][0]))
                else:
                    print("There has been a tie for one position")

        ## Add data for all 6 players' odds
        #TODO: add TBD error checking here
        for i,val in enumerate(data_arr_part2):
            if('1. ' in val):
                if(data_arr_part2[i+1] == 'SCRATCHED' or data_arr_part2[i+1] == 'SCRATCHED (LATE)'):
                    p1.append('-')
                else:
                    p1.append(str(data_arr_part2[i+2])) #get the first value of that string
            elif('2. ' in val):
                if(data_arr_part2[i+1] == 'SCRATCHED' or data_arr_part2[i+1] == 'SCRATCHED (LATE)'):
                    p2.append('-')
                else:
                    p2.append(str(data_arr_part2[i+2])) 
            elif('3. ' in val):
                if(data_arr_part2[i+1] == 'SCRATCHED' or data_arr_part2[i+1] == 'SCRATCHED (LATE)'):
                    p3.append('-')
                else:
                    p3.append(str(data_arr_part2[i+2])) 
            elif('4. ' in val):
                if(data_arr_part2[i+1] == 'SCRATCHED' or data_arr_part2[i+1] == 'SCRATCHED (LATE)'):
                    p4.append('-')
                else:
                    p4.append(str(data_arr_part2[i+2])) 
            elif('5. ' in val):
                if(data_arr_part2[i+1] == 'SCRATCHED' or data_arr_part2[i+1] == 'SCRATCHED (LATE)'):
                    p5.append('-')
                else:
                    p5.append(str(data_arr_part2[i+2])) 
            elif('6. ' in val):
                if(data_arr_part2[i+1] == 'SCRATCHED' or data_arr_part2[i+1] == 'SCRATCHED (LATE)'):
                    p6.append('-')
                else:
                    p6.append(str(data_arr_part2[i+2])) 
    else:
        r1.append('-')
        r2.append('-')
        r3.append('-')
        p1.append('-')
        p2.append('-')
        p3.append('-')
        p4.append('-')
        p5.append('-')
        p6.append('-')
        abdn_flag = False

## If there are less than 12 races at a venue, fill in the blanks with '-'
complete_data = [r1, r2, r3, p1, p2, p3, p4, p5, p6]
print(complete_data)
for i in complete_data:
    while len(i) != 12:
        i.append('-')

## Write/Append the current venue's data into the file
with open(filename, 'a+') as f:
    writer = csv.writer(f)

    # check if the file is empty: if NO, write newline char, if YES do nothing,
    f.seek(0) # Move read cursor to the start of file
    data = f.read(10)
    if len(data) > 0:
        f.write("\n")
    else:
        writer.writerow(['R1','R2','R3','R4','R5','R6',\
                        'R7','R8','R9','R10','R11','R12'])
    writer.writerow([venue_name,'-','-','-','-','-','-','-','-','-','-','-'])
    writer.writerows([p1, p2, p3, p4, p5, p6, r1, r2, r3])

driver.close()