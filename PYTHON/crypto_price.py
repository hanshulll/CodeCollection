import requests

url = "https://api.wazirx.com/api/v2/tickers"
response = (requests.get(url).json())
print(response["btcinr"]["last"])
