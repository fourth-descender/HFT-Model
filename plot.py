import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns

# read the data from the CSV file.
data = pd.read_csv('plot/points.csv')

# create a new array for the x-values.
x_values = np.linspace(0.1, 1, len(data['StockMidPrices']))

# use a style for the plot.
sns.set_style('darkgrid')  # use seaborn-darkgrid style

# increase the size of the plot.
plt.figure(figsize=(10, 6))

# plot the data with increased line width.
plt.plot(x_values, data['AskPrices'], label='Ask Prices', color='red', linewidth=2)
plt.plot(x_values, data['BidPrices'], label='Bid Prices', color='green', linewidth=2)
plt.plot(x_values, data['StockMidPrices'], label='Stock MidPrices', color='blue', linewidth=2)

# add labels and title.
plt.xlabel('Time', fontsize=14)
plt.ylabel('Price', fontsize=14)
plt.title('Prices over Time', fontsize=16)

# add a legend.
plt.legend()

# save the plot to a file.
plt.savefig('plot/plot.png')