import os



def main():
    print("Hello World!")
    print(dirSize())

def dirSize():
    #*(frick) python
    b = os.path.getsize("..")
    return b

if __name__ == "__main__":
    main()