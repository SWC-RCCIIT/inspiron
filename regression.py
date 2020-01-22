reg=linear_model.LinearRegression()
reg.fit(df[['voltage','temperature']],df.current)
reg.coef_
reg.intercept_
reg.predict([[13.2,36]])
x=reg.predict([[13.2,36]])
print(x)
y=float(((x-3.7)/3.7)*100)
print(y)
if x > 3.7:
    print("current is faulty")
%matplotlib inline
plt.figure(figsize=(10,5))
plt.plot(df.current,df.voltage)
plt.plot(df.current,df.voltage,'ro')
plt.xlabel('current')
plt.ylabel('voltage')
plt.title('current vs voltage')

plt.show()
%matplotlib inline
plt.figure(figsize=(10,5))
plt.plot(df.current,df.temperature)
plt.plot(df.current,df.temperature,'ro')
plt.xlabel('current')
plt.ylabel('temperature')
plt.title('current vs temperature')
plt.show()