import pandas as pd
import matplotlib.pyplot as plt

# Read the data from the CSV file
data = pd.read_csv('output.csv')

# Plot the data
plt.plot(data['AskPrices'], label='Ask Prices', color='red')
plt.plot(data['BidPrices'], label='Bid Prices', color='green')
plt.plot(data['StockPrices'], label='Stock Prices', color='blue')

# Add labels and title
plt.xlabel('Time')
plt.ylabel('Price')
plt.title('Prices over Time')

# Add a legend
plt.legend()

# Display the plot
plt.show()