import numpy as np
import pandas as pd
from sklearn.preprocessing import StandardScaler

data=pd.read_csv('cleaned_boston_housing.csv')                   # 读取文件

target_column=data.columns[-1]                                   #设置目标项，已知最后一项代表价格

corr0=data.drop(target_column,axis=1).corr().abs()                    #寻找相关性
upper=corr0.where(np.triu(np.ones(corr0.shape),k=1).astype(np.bool_))

to_drop=[column for column in upper.columns if any(upper[column]>0.9)]       #除去过于相关的数据

data=data.drop(to_drop,axis=1)                               #将去除最后一项的数据赋值到data

x=data.drop(target_column,axis=1).values
y=data[target_column].values                                          #分别对x和y赋值

scaler=StandardScaler()
x_scaler=scaler.fit_transform(x)                                   #标准化处理

x_scaler=np.hstack((np.ones((x_scaler.shape[0],1)),x_scaler))          # 在特征矩阵中添加截距项，在特征矩阵的第一列添加全为 1 的列，用于拟合线性回归模型的截距

theta_ls=np.linalg.inv(x_scaler.T@x_scaler)@x_scaler.T@y               #求解最小二乘法的参数

theta=np.zeros(x_scaler.shape[1])
m=len(y)
rate=0.01
times=1000
for i in range(times):
    y_pred=x_scaler@theta                              #求预测值
    error=y_pred-y                                      #求误差
    theta=theta-(rate/m)*(x_scaler.T@error)             #更新参数
theta_gd=theta

print("最小二乘法：",theta_ls)
print("逻辑回归：",theta_gd)
