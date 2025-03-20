import numpy as np
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

x,y=make_classification(n_samples=1000,n_features=10,n_informative=5,n_redundant=0,random_state=42)             #初始化一个数据集
y=y.reshape(-1,1)                                 #把y转成矩阵的形式

x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.2,random_state=42)          #把数据集分成训练集和测试集

rate=0.01                           #学习率
times=1000                           #迭代步数
m,n=x_train.shape                     #样本数量和特征数量
weight=np.zeros((n,1))                #设置一个零向量
bias=0                               #设置所需参数

for i in range(times):
    z=np.dot(x_train,weight)+bias          #计算线性组合
    y_pred=1/(1+np.exp(-z))

    dw=(1/m)*np.dot(x_train.T,(y_pred-y_train))
    db=(1/m)*np.sum(y_pred-y_train)

    weight-=rate*dw                #调整权重
    bias-=rate*db

z_test=np.dot(x_test,weight)+bias             #预测测试集
y_pred_test=1/(1+np.exp(-z_test))
y_pred_class=[1 if i>0.5 else 0 for i in y_pred_test]
y_pred_class=np.array(y_pred_class)

accuracy=accuracy_score(y_test,y_pred_class)        #输出准确度
print(accuracy)


