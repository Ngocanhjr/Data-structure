set terminal wxt size 1200,900 title 'Van b?n: 'Hell''
set multiplot layout 5,1 title 'Mã hóa và Bi?n di?u cho: Van b?n: 'Hell'' font ',14'
set grid xtics
set key off
set title 'Tín hi?u s?: NRZ-Level'
set xlabel 'Th?i gian'
set ylabel 'Ði?n áp'
plot 'nrz_data.dat' with steps
set title 'Tín hi?u s?: Manchester'
plot 'manchester_data.dat' with steps
set title 'Tín hi?u tu?n t?: Bi?n di?u cu?ng d? (ASK)'
set ylabel 'Biên d?'
plot 'ask_data.dat' with lines
set title 'Tín hi?u tu?n t?: Bi?n di?u t?n s? (FSK)'
plot 'fsk_data.dat' with lines
set title 'Tín hi?u tu?n t?: Bi?n di?u pha (PSK)'
plot 'psk_data.dat' with lines
unset multiplot
