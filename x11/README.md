
官网网址
https://www.x.org/

相关概念介绍
https://www.x.org/wiki/guide/concepts/

本地下载vcxsrv  https://sourceforge.net/projects/vcxsrv/ ,安装X windows 服务器
服务器安装x11  apt install libx11-dev

Host server_ip
HostName server_ip
ForwardX11 yes
ForwardX11Trusted yes
ForwardAgent yes
User user_name

/etc/ssh/sshd_config
  X11Forwarding yes

ssh -Y user_name@server_ip
xclock
