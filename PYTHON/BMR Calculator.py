print('This is BMR base on Mifflin St. Jeor')
print('Basal metabolic rate is amount of energy expended per day at rest.')

sex = input('Please enter your sex(Men/Women): ').lower()
height = float(input('Please enter your height(cm): '))
weight = float(input('Please enter your weight(kg): '))
age = int(input('Please enter your age: '))

if sex == 'men':
    bmr = 10*weight+(6.25*height)-(5*age) + 5
    print('This is your BMR: {}'.format(bmr))
elif sex == 'women':
    bmr = 10*weight+(6.25*height)-(5*age) -161
    print('This is your BMR: {}'.format(bmr))
else:
    print('ERROR')

