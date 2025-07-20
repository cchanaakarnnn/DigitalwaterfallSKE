import queQ
import theSerial
import Picture
import time

hz = 50
solinoid_num = 40
delay_between_pic = 10
#ms


def setup_main():
    queQ.testsetup()
    theSerial.setup_SE()

def run_main():
    pic_rightnow = None
    line = 0
    index = 0 # traverse through lines
    running = True

    while running:
        try:
            if queQ.getQsize() > 0 and pic_rightnow is None:
                data = '1' * 40 + '\n'
                # print(f"[main] : Sending init data: {data.strip()}")
                theSerial.send_SE(data)
                time.sleep(1)

                # Load new picture data
                pic_rightnow = queQ.getQelement(0)
                queQ.removeQ(0)
                queQ.appendQ(pic_rightnow)
                line = len(pic_rightnow)

            # Prepare and send data line by line
            data = ''.join(str(i) for i in pic_rightnow[line - index - 1]) + '\n'
            # print(f"[main] : Sending data line: {data.strip()}")
            theSerial.send_SE(data)
            time.sleep(1 / hz)

        except OSError as e:
            print(f"[main] : OSError encountered in send_SE - {e}")
            time.sleep(0.3)
            theSerial.setup_SE()  # Attempt to recover by reinitializing SE

        # Increment index, reset if picture ends
        index += 1
        if index >= line:
            pic_rightnow = None
            index = 0
            print("[main] : Resetting for next picture")




if __name__ == '__main__':
    queQ.testsetup()
    setup_main()
    run_main()
