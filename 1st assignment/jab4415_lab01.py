import os



def main():
    print("Hello World!")
    print(dirSize("."))

def dirSize(folder):
    #*(frick) python
    total_size = os.path.getsize(folder) - 4096
    for item in os.listdir(folder):
        itempath = os.path.join(folder, item)
        if os.path.isfile(itempath):
            total_size += os.path.getsize(itempath)
        elif os.path.isdir(itempath):
            total_size += dirSize(itempath)
    return total_size

if __name__ == "__main__":
    main()