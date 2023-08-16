import os
import shutil

i = 0


def recursive_listdir(path):
    global i
    files = os.listdir(path)
    for file in files:
        file_path = os.path.join(path, file)

        if os.path.isfile(file_path):
            if file.lower().endswith(('.png', '.jpg', '.jpeg', '.gif', '.bmp')):
                # 下载图片
                download_image(file_path, i)
                print(i)
                i += 1

        elif os.path.isdir(file_path):
            recursive_listdir(file_path)


def download_image(image_path, i):
    shutil.copy(image_path,
                'F:\\Picture\\' + str(i) + '.' + image_path.split(".")[1])


if __name__ == '__main__':
    folder_path = 'C:\\Users\\幻影\\Documents\\Tencent Files\\601019100\\Image'
    recursive_listdir(folder_path)
