密码学原理 - 实验工具
===

#### 维吉尼亚密码

** 所有分析工具均支持管线命令(如cat, tee)和参数列表, 方便输入输出重定向 **

```sh
# 用长度为4的随机密钥加密plaintext文件
# 默认输出密文到标准输出
./vigenere_encrypt 4 plaintext

# 分析各字符出现频率
cat plaintext | ./vigenere_encrypt 4  | ./summary

# 频率的简单统计
./vigenere_encrypt 4 plaintext | ./summary | ./statistic

# 用长度为2的密钥猜测实际密钥长度, 计算重合指数IC
./vigenere_encrypt 4 plaintext | ./summary | ./icanalyze 2
```
