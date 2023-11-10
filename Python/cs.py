import os
import shutil

i = 1


def recursive_listdir(path, save_path, lx):
    global i
    files = os.listdir(path)
    for file in files:
        file_path = os.path.join(path, file)
        print(file_path)
        if os.path.isfile(file_path):
            for k in lx:
                if file.lower().endswith(k):
                    # 下载图片
                    download_image(file_path, save_path, i)
                    i += 1
                    break

        elif os.path.isdir(file_path):
            recursive_listdir(file_path, save_path, lx)


def download_image(image_path, save_path, i):
    shutil.copy(image_path,
                save_path + '\\' + str(i) + '.'+image_path.split(".")[1])


if __name__ == '__main__':
    folder_path = input('请输入爬取的文件夹路径：')
    save_path = input('请输入保存的文件夹路径：')
    lx = []
    s = input('请输入要爬取的文件类型数量：')
    for j in range(int(s)):
        lx.append(input('  ' + str(j + 1) + '：'))
    recursive_listdir(folder_path, save_path, lx)
