import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets, linear_model
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score, accuracy_score

diabetes = datasets.load_boston()
print(diabetes)
X = diabetes.data[:, np.newaxis, 2]
print("Data shape: ", X.shape)

x_train, x_test, y_train, y_test = train_test_split(X, diabetes.target, test_size=0.1, random_state=4)
regr = linear_model.LinearRegression()
regr.fit(x_train, y_train)
y_pred = regr.predict(x_test)

print('Coefficients: ', regr.coef_)

print("Mean squared error: %.2f"
      % mean_squared_error(y_test, y_pred))

plt.scatter(x_test, y_test,  color='black')
plt.plot(x_test, y_pred, color='blue', linewidth=3)
plt.show()