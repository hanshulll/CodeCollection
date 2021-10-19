# This is my first ever Python project.
from gtts import gTTS  # use pip install gtts to import the gtts module
import os  # importin the os module

# This is used for fetching the file by the name of text.txt in the same folder if you want to fetch other files you can enter there address here to do so
fh = open("test.txt", "r")
# The fetched file is read in this piece of code and even the spaces involve in the test,txt file are being ignored in the reading process.
Text = fh.read().replace("\n", " ")

language = 'en'  # Set to the langauage in which you want to hear your text.

# Delivered text and all its properties are mentioned over here
output = gTTS(text=Text, lang=language, slow=False)

# Saving the file by the name o sound .mp3 you could change the name of the sound file as per your choice.
output.save("awaz.mp3")
fh.close()  # Close the fetch file
# Start thethe sound file created in this programme.
os.system("start awaz.mp3")
