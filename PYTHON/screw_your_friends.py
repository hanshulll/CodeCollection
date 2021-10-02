import webbrowser
import random
import time
while True:
 sites=random.choice(['google.com','amazon.in','flipkart.com','youtube.com'])
 visit="http://{}".format(sites)
 webbrowser.open(visit)
 seconds=random.randrange(0,2) #set time between 20 to 50 for testing
 time.sleep(seconds)
