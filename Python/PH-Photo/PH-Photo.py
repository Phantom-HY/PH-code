import requests
import os
import re

keyword = input("图片:")
page_num = int(input("爬取数量:"))
save_dir = input("保存目录：") + '\\' + keyword


def Get_photos(keyword, page_num, save_dir):
    header = {
        'User-Agent':
        'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.108 Safari/537.36'
    }
    # 请求的 url
    url = 'https://image.baidu.com/search/acjson?'
    n = 1
    for pn in range(0, page_num, 1):
        # 请求参数
        param = {
            'tn': 'resultjson_com',
            'ipn': 'rj',
            'ct': 201326592,
            'is': '',
            'fp': 'result',
            'queryWord': keyword,
            'cl': 2,
            'lm': -1,
            'ie': 'utf-8',
            'oe': 'utf-8',
            'adpicid': '',
            'st': -1,
            'z': '',
            'ic': '',
            'hd': '',
            'latest': '',
            'copyright': '',
            'word': keyword,
            's': '',
            'se': '',
            'tab': '',
            'width': '',
            'height': '',
            'face': 0,
            'istype': 2,
            'qc': '',
            'nc': '1',
            'fr': '',
            'expermode': '',
            'force': '',
            'cg': '',  # 这个参数没公开，但是不可少
            'pn': pn,
            'rn': '1',  # 每页显示 100 条
            'gsm': '1e',
            '1618827096642': ''
        }
        request = requests.get(url=url, headers=header, params=param)
        request.encoding = 'utf-8'
        html = request.text
        image_url_list = re.findall('"thumbURL":"(.*?)",', html, re.S)
        if not os.path.exists(save_dir):
            os.makedirs(save_dir)

        for image_url in image_url_list:
            image_data = requests.get(url=image_url, headers=header).content
            with open(os.path.join(save_dir, keyword + str(n) + '.jpg'),
                      'wb') as fp:
                fp.write(image_data)
            print(keyword + str(n) + '.jpg保存成功   保存地址：' + save_dir + '\\' +
                  keyword + str(n) + '.jpg')
            if n == page_num:
                return 1
            n = n + 1
    print('爬取结束')


Get_photos(keyword, page_num, save_dir)
