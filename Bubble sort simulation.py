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
    mpl.pause(0.2)  # tam dung man hinh de quan sat


def bubbleSort(array):
    for i in range(len(array)-1):
        swapped = False
        j = len(array) - 1
        drawGraph(array, j, j - 1)  # ve mau 2 cot dang xet
        while j > i:
            if array[j] < array[j - 1]:
                array[j], array[j - 1] = array[j - 1], array[j]
                swapped = True  # co hoan vi
            drawGraph(array, j, j - 1)
            j -= 1
        if not swapped:
            break
    mpl.show()


np.random.seed(0)  # dat lai ham range
array = np.random.randint(1, 120, 10)  # array ngau nhien tu 1 den 199 gom 1 phan tu
drawGraph(array, -1, -1)  # trang thai ban dau tat ca deu xanh
bubbleSort(array)

