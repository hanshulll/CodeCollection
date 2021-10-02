from bs4 import BeautifulSoup  #Importing the Beautiful Soup Library
import requests				   #Importing the requests library
import time					   #Importing the time library
import csv					   #Importing the csv module

response = requests.get('https://www.flipkart.com/search?q=nokia+smartphones&sid=tyy%2C4io&as=on&as-show=on&otracker=AS_QueryStore_OrganicAutoSuggest_0_10_na_na_pr&otracker1=AS_QueryStore_OrganicAutoSuggest_0_10_na_na_pr&as-pos=0&as-type=RECENT&suggestionId=nokia+smartphones&requestId=675612e2-512b-4d0e-8b75-6bdf91921d7c&as-backfill=on')

soup = BeautifulSoup(response.text, 'lxml')
mname, mrating, mprice, mdesc = list(), list(), list(), list()
mobile_name = soup.find_all(class_='_3wU53n')
rating = soup.find_all(class_='hGSR34')
price = soup.find_all(class_='_1vC4OE _2rQ-NK')
description = soup.find_all(class_='vFw0gD')

for a,b,c,d in zip(mobile_name, rating, price, description):
	mname.append(a.get_text())
	mrating.append(b.get_text())
	mprice.append(c.get_text())
	mdesc.append(d.get_text())

with open('flipkart.csv','w',encoding="utf-8", newline = '') as csvfile:
	writer = csv.writer(csvfile)
	writer.writerow(['Mobile Name', 'Ratings', 'Pricing', 'Description'])
	for a,b,c,d in zip(mname, mrating, mprice, mdesc):
		writer.writerow([a.strip(), b.strip(), c.strip(), d.strip()])
