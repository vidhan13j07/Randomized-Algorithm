import pandas as pd
from matplotlib import pyplot as plt 
file = 'out.csv'

df = pd.read_csv(file,index_col = 'Size of Input')

print df.head(2)

df.plot()

plt.show()