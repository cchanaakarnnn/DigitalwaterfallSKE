import numpy
import image

The_queue = []

def printallQ():
    for q in The_queue:
        print(q)

def removeQ(index):
    if index >= len(The_queue):
        print("[queQ] : CAN'T REMOVE INDEX OUT OF RANGE")
    else:
        The_queue.pop(index)

def appendQ(images:numpy.ndarray, invert=False):
    if invert:
        images = image.invert(images)
    The_queue.append(images)

def getQelement(index):
    if index >= len(The_queue):
        print("[queQ] : CAN'T RETRIVE DATA INDEX OUT OF RANGE")
        return None
    else:
        return The_queue[index]

def getQsize():
    return len(The_queue)

def testsetup():
    for i in range(1,13 ):
        resizeimg = image.pictonumpy('Picture/Openning Text/' + str(i) + '.png', solinoid_num=40)
        # resizeimg = image.invert(resizeimg)
        appendQ(resizeimg)
        print(f'[queQ] : Image "{str(i)}" has been added to the que')


def getQ():
    return The_queue

if __name__ == "__main__":
    testsetup()
