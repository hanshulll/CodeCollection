from datetime import datetime

day1 = input('Enter a date in DD/MM/YYYY format: ')
day2 = input('Enter a date in DD/MM/YYYY format: ')
new_day1 = datetime.strptime(day1, "%d/%m/%Y")
new_day2 = datetime.strptime(day2, "%d/%m/%Y")
total_days = new_day2 - new_day1

print(total_days.days)
