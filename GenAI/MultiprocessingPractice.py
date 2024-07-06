import multiprocessing, time

A = 0

def print_numbers():
    global A
    for i in range(5):
        print('i:', i)
        print('A:', A)

        A += 1
        time.sleep(1)

if __name__ == '__main__':
    process1 = multiprocessing.Process(target=print_numbers)
    process2 = multiprocessing.Process(target=print_numbers)

    process1.start()
    process2.start()

    process1.join()
    process2.join()