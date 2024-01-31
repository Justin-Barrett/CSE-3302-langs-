import os



def main():
    print(dirSize("."))

# takes in a file/directory path
def dirSize(folder):
    #*(frick) python
    total_size = os.path.getsize(folder) - 4096
    for entries in os.listdir(folder):
        #thisEntry = the specific entry in the list
        thisEntry = os.path.join(folder, entries)
        if os.path.isfile(thisEntry):
            total_size += os.path.getsize(thisEntry)
        elif os.path.isdir(thisEntry):
            total_size += dirSize(thisEntry)
    return total_size

if __name__ == "__main__":
    main()