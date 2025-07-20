import queQ
import theSerial
import Picture
import time

hz = 40
solinoid_num = 40
delay_between_pic = 100 #ms


def setup_main():
    queQ.testsetup()
    theSerial.setup_SE()

def run_main():
    running = True
    while running:
        try:
            if queQ.getQsize() > 0:
                # Load new picture data
                pic_rightnow = queQ.getQelement(0)
                queQ.removeQ(0)
                queQ.appendQ(pic_rightnow)
                # input('Press Enter : ')
                # time.sleep(0.1)
                picstr=''
                for i in pic_rightnow:
                    for j in i:
                        picstr+=str(j)
                picstr += '\n'
                # print(picstr)
                theSerial.send_SE(picstr)
                print("Send")
                line = len(picstr) // solinoid_num
                time.sleep((1/hz)*line*1.1)
                print("looop")
                time.sleep(1)
                print("[main] : Resetting for next picture")
        except OSError as e:
            print(f"[main] : OSError encountered in send_SE - {e}")
            time.sleep(2)
            theSerial.setup_SE()  # Attempt to recover by reinitializing SE


if __name__ == '__main__':
    setup_main()
    run_main()
