import matplotlib.pyplot as mpl
import numpy as np  # thu vien xu ly mang so nguyen


def drawGraph(array, index1, index2):
    mpl.clf()  # xoa bieu do cu de ve bieu do moi
    colors = [
        "green" if i != index1 and i != index2 else "yellow" for i in range(len(array))
    ]
    mpl.bar(range(len(array)), array, color=colors)  # dai, cao, mau
    mpl.xlabel("Index")
    mpl.ylabel("Value")
    mpl.title("Bubble sort graph")
    mpl.pause(0.5)  # tam dung man hinh de quan sat
def selectionSort(array):  
    for i in range(len(array)-1):
        j=i+1
        pos=i
        while j<len(array):
            drawGraph(array, i, j)
            if array[pos]>array[j]:
                pos=j
            j+=1
        if pos != i:
            array[i], array[pos] = array[pos], array[i]
            drawGraph(array, i, pos)
    mpl.show()

np.random.seed(0)  # dat lai ham range
array = np.random.randint(1, 120, 10)  # array ngau nhien tu 1 den 199 gom 1 phan tu
drawGraph(array, -1, -1)  # trang thai ban dau tat ca deu xanh
selectionSort(array)
