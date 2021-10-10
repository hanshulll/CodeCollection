file1 = open('letter.txt', 'w')
L = ["To \n", "The Principal \n", "KV\n", "Sir, \n\n", "This is ...... studying in your school wants to inform you that I was absent from...to.......due to health issues. The test report and prescription is attached with the letter.... \n", "Thanking you for understanding \n", "Yours sincerly, \n", "........ \n", "Your ID \n"]  
# Writing multiple strings
# at a time
file1.writelines(L)
  
# Closing file
file1.close()
  
# Checking if the data is
# written to file or not
file1 = open('letter.txt', 'r')
print(file1.read())
file1.close()