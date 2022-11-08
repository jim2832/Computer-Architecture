#!/bin/bash
#Program:
#	This program shows final thermal map in /home/sniper/Downloads/result
#History
#2016/02/26	Andy First release
#2016/03/02     auto open .svg and delete useless files
#		user defined benchmarks name
#2016/03/15     make gif for time=0~end  
#               max and min tem write in file /home/sniper/Downloads/HotSpot-6.0/grid_thermal_map.pl        

PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

declare -i datanum=0



while [ -e out${datanum}.ptrace ]
do

cp out${datanum}.ptrace ../nehalem.flp /home/sniper/Downloads/HotSpot-6.0

cd /home/sniper/Downloads/HotSpot-6.0

./hotspot -c hotspot.config -f nehalem.flp -p out${datanum}.ptrace \
           -steady_file out.steady -model_type grid \
           -grid_steady_file out.grid.steady

./grid_thermal_map.pl nehalem.flp out.grid.steady > out.svg

cp out.svg ../result/svg/out${datanum}.svg

cd ~/Downloads/result/svg

if [ ${datanum} -lt 10 ];then

convert -resize 900x500 out${datanum}.svg ../png/out0${datanum}.png

else

convert -resize 900x500 out${datanum}.svg ../png/out${datanum}.png

fi

cd ~/Downloads/HotSpot-6.0

make cleano

rm -f out${datanum}.ptrace out.svg out.steady out.grid.steady

datanum=${datanum}+1

cd /home/sniper/Downloads/convert/out/

done



exit 0

