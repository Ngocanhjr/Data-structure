--cau 2
select * from khuvuc;
select * from may;
select * from loai;
select * from phong;
select * from phanmem;
select * from caidat;

select loai.tenloai from
loai join may on loai.idloai = may.idloai
where  may.idmay = 'p8';

--cau 3
select phanmem.tenpm from
loai join phanmem on loai.idloai = phanmem.idloai
where loai.idloai = 'UNIX';

--cau 4
select DISTINCT phong.tenphong, phong.ip, phong.mp from
loai join may on loai.idloai = may.idloai
     join phong on phong.mp = may.mp
where loai.idloai = 'UNIX' or loai.idloai = 'PCWS';

--cau 5
select DISTINCT phong.tenphong, phong.ip, phong.mp from
loai join may on loai.idloai = may.idloai
     join phong on phong.mp = may.mp
where (loai.idloai = 'UNIX' or loai.idloai = 'PCWS') AND may.ip ='130.120.80'
order by  phong.mp asc;

--cau 6
select count(*) sophanmem from
may join caidat on may.idmay = caidat.idmay
    join phanmem on phanmem.idpm = caidat.idpm
    where  may.idmay = 'p6';
    
select count(*) from caidat GROUP BY idmay HAVING (idmay ='p6');
    
--cau 7
select count(*)sophanmem  from
may join caidat on may.idmay = caidat.idmay
    join phanmem on phanmem.idpm = caidat.idpm
    where  phanmem.idpm = 'log1';

select count(*) from caidat GROUP BY idpm HAVING (idpm ='log1');

--cau 8
select (ip || '.' ||ad) FROM may where idloai ='TX';

--cau 9
select idmay , count(idpm) from caidat GROUP BY idmay;

-- cau 10 














