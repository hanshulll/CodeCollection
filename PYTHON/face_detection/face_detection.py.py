# Importing necessary libraries
import cv2
import numpy as np

# Importing Haarcascade Classifier to detect Face features
face_cascade = cv2.CascadeClassifier('./haarcascade_frontalface_alt.xml')

# Capturing video source from webcam
video_capture = cv2.VideoCapture(0)

while True:

    # Reading frames from video source
    _, frame = video_capture.read()

    # Converting frames in to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Detecting faces in the frame
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)

    # Drawing rectangles on faces detected
    for (x, y, w, h) in faces:
        face = gray[y:y + h, x:x + w]
        resized_image = cv2.resize(face, (50, 50))
        normalized_image = resized_image / 255.0
        reshaped_image = np.reshape(normalized_image, (1, 50, 50, 1))
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 0), 2)

    # Showing drawed frame
    cv2.imshow('Video', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Exiting video capturing process
video_capture.release()
cv2.destroyAllWindows()
