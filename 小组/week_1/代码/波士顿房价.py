import pandas as pd
import matplotlib
matplotlib.use('QtAgg')
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler

try:
    data=pd.read_csv('boston_housing.csv')                            #读取csv文件
    for col in data.columns:
        data[col]=pd.to_numeric(data[col],errors='coerce')             #把内容转化为数值类型，如果无法转化，则变为NaN
except FileNotFoundError:                                             #处理可能出现的错误
    print("未找到文件，请检查文件路径")

new_columns=['CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE', 'DIS', 'RAD', 'TAX', 'PTRATIO', 'B', 'LSTAT','MEDV']
data.columns=new_columns                               #把数据的列索引替换

data=data.dropna()                                      #删去错误数据

scaler=StandardScaler()                                  #把数据集标准化，便于后续处理
data_scaler=scaler.fit_transform(data)
data_scaler=pd.DataFrame(data_scaler,columns=data.columns)

features=data.columns[:-1]                       #获取除价格外的列索引，方便待会绘图
fig,axes=plt.subplots(4,4,figsize=(15,15))
axes=axes.flatten()                          #扁平化处理

for i,feature in enumerate(features):                   #逐步绘图
    axes[i].scatter(data[feature],data['MEDV'])
    axes[i].set_xlabel(feature)
    axes[i].set_ylabel('MEDV')

for j in range(len(features),len(axes)):                #隐藏无用的图像
    axes[j].axis('off')

plt.tight_layout(pad=2.0,h_pad=4.0,w_pad=2.0)           #调整图像间的距离，避免遮挡
plt.show()

cleaned_file_path='try.csv'                              #将处理好的数据集保存为csv文件
data.to_csv(cleaned_file_path,index=False)
print("已保存")