import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import pyplot
from statsmodels.graphics.gofplots import qqplot
from pandas.plotting import scatter_matrix
from sklearn import linear_model
df=pd.read_csv("dataset1.csv")
df