"""
Python program to scrap internship details from internshala website

"""

from bs4 import BeautifulSoup
import requests

source = requests.get('https://internshala.com/internships').text
soup = BeautifulSoup(source, 'lxml')

listings = soup.find_all('div', class_ = 'individual_internship')

result = list()

for listing in listings : 
    result.append({
        'title' : listing.a.text,
        'link' : listing.a['href'],
        'company' : listing.find('div', class_='company_name').a.text.strip(),
        'time' : listing.find('div', id='start-date-first').text.strip()
    })

print(result)

flag = True
f = input("Do you want to continue ? (y / n) ")
if f.lower() == 'y' : 
    flag = True
else : 
    flag = False

i = 2       #   iterator to get the next page
while flag : 
    next_page = soup.find('a', class_ = 'next_page')
    if next_page is not None : 
        page = 'https://internshala.com/internships/page-{}'.format(i)
        print(page)
        i+=1
        source = requests.get(page).text
        soup = BeautifulSoup(source, 'lxml')
        result = list()

        for listing in listings : 
            result.append({
                'title' : listing.a.text,
                'link' : listing.a['href'],
                'company' : listing.find('div', class_='company_name').a.text.strip(),
                'time' : listing.find('div', id='start-date-first').text.strip()
            })

        print(result)
    else :
        print("Listings finished")
    
    f = input("Do you want to continue ? (y / n) ")
    if f.lower() == 'y' : 
        flag = True
    else : 
        flag = False