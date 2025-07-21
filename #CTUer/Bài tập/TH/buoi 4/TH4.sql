


--CAU 3
select * from ktrucsu
where hoten_kts like '%le%' and nams_kts = '1956';

--cau 4
select * from CGTRINH
where ngay_bd BETWEEN TO_DATE('09-01-1994') and TO_DATE('10-20-1994');

--cau 5
select *from KTRUCSU;
select * from CHUTHAU;
select * from CGTRINH;
select * from KTRUCSU;
select * from congnhan;
select * from thamgia;
select * from thietke;

select ten_ctr, diachi_ctr from CGTRINH
where ten_thau = 'cty xd so 6';


--cau 6
select DISTINCT cthau.ten_thau, cthau.dchi_thau
from ktrucsu KTS join thietke TK on kts.hoten_kts = tk.hoten_kts
                join cgtrinh CT on ct.stt_ctr = tk.stt_ctr
                join chuthau CThau on cthau.ten_thau = ct.ten_thau
where ct.tinh_thanh = 'can tho' and tk.hoten_kts ='le kim dung';

--cau 7
select ktx.noi_tn from
ktrucsu ktx join thietke tk on ktx.hoten_kts = tk.hoten_kts
            join cgtrinh ct on ct.stt_ctr = tk.stt_ctr
where ct.ten_ctr ='khach san quoc te' and ct.tinh_thanh ='can tho';

--cau 8
select DISTINCT cn.hoten_cn,cn.nams_cn,cn.nam_vao_n from
congnhan CN join thamgia TG on cn.hoten_cn = tg.hoten_cn
            join cgtrinh CT on ct.stt_ctr  = tg.stt_ctr
where (cn.ch_mon ='dien' or cn.ch_mon = 'han') and ct.ten_thau = 'le van son';


--cau 9
select cn.hoten_cn from
congnhan CN join thamgia TG on cn.hoten_cn = tg.hoten_cn
            join cgtrinh CT on ct.stt_ctr  = tg.stt_ctr
where tg.ngay_tgia BETWEEN '12-15-1994' and '12-31-1994'
and ct.ten_ctr = 'khach san quoc te' 
and ct.tinh_thanh = 'can tho'; 

--cau 10
SELECT DISTINCT kts.hoten_kts, kts.nams_kts FROM
ktrucsu kts join thietke tk on kts.hoten_kts = tk.hoten_kts
            join cgtrinh ct on ct.stt_ctr = tk.stt_ctr
where kts.noi_tn = 'tp hcm' and ct.kinh_phi > 400;

--cau 11
select cn.hoten_cn, cn.ch_mon from 
ktrucsu kts join thietke tk on kts.hoten_kts = tk.hoten_kts
            join cgtrinh ct on ct.stt_ctr = tk.stt_ctr
            join thamgia tg on tg.stt_ctr = tk.stt_ctr
            join congnhan cn on cn.hoten_cn = tg.hoten_cn
where kts.hoten_kts ='le thanh tung';

--cau 12
select ten_ctr, kinh_phi as max from cgtrinh
where kinh_phi =(SELECT max (kinh_phi) from cgtrinh );


--cau 13 
SELECT hoten_kts, nams_kts as trenhat from ktrucsu
where nams_kts = (select max (nams_kts) from ktrucsu);

--cau 14
select ten_thau, sum(kinh_phi) as toal from cgtrinh
GROUP BY ten_thau;

--cau cau 15
select chu.ten_thau, chu.dchi_thau from
cgtrinh ct join chuthau chu on ct.ten_thau = chu.ten_thau
where ct.kinh_phi = (select min (kinh_phi) from cgtrinh);

--cau 16
select hoten_kts, sum(thu_lao) from
thietke 
GROUP BY thietke.hoten_kts
having sum(thu_lao) >25;

-- cau 17
select count(hoten_kts) as soluong from
(select thietke.hoten_kts
from thietke
GROUP BY thietke.hoten_kts
having sum(thietke.thu_lao) >25);

--cau 18

select hoten_kts, count(stt_ctr)soluongcongtrinh from
thietke
group by hoten_kts; 

--cau 19
select thamgia.stt_ctr,cgtrinh.ten_ctr,  count(thamgia.hoten_cn)so_luong_cong_nhan from 
thamgia join cgtrinh on thamgia.stt_ctr = cgtrinh.stt_ctr
group by thamgia.stt_ctr, cgtrinh.ten_ctr;


-- cau 20 
select thamgia.stt_ctr,cgtrinh.ten_ctr,  count(thamgia.hoten_cn)so_luong_cong_nhan from 
thamgia join cgtrinh on thamgia.stt_ctr = cgtrinh.stt_ctr
group by thamgia.stt_ctr, cgtrinh.ten_ctr having count(thamgia.hoten_cn)= (

    select max(so_luong_cong_nhan)soluong from(
        select thamgia.stt_ctr,cgtrinh.ten_ctr,  count(thamgia.hoten_cn)so_luong_cong_nhan from 
        thamgia join cgtrinh on thamgia.stt_ctr = cgtrinh.stt_ctr
        group by thamgia.stt_ctr, cgtrinh.ten_ctr)
    );


--cau 21
select tinh_thanh , avg(kinh_phi) kinh_phi_trung_binh from cgtrinh
group by tinh_thanh;

-- cau 22
-- đề sai nên thay lại = le manh quoc
select cgtrinh.ten_ctr, cgtrinh.diachi_ctr from
cgtrinh join thamgia on cgtrinh.stt_ctr = thamgia.stt_ctr
where thamgia.hoten_cn = 'le manh quoc' and thamgia.ngay_tgia = to_date ('18-12-1994','DD-MM-YYYY'); 

--cau 23

select distinct HOTEN_KTS
from thietke 
join cgtrinh ct1  on ct1.stt_ctr = thietke.stt_ctr
join cgtrinh ct2  on ct1.stt_ctr = thietke.stt_ctr
where ct1.TEN_THAU= 'cty xd so 6' and ct2.ten_thau = 'phong dich vu so xd';

--cau 24
select DISTINCT congnhan.hoten_cn
from congnhan
join thamgia on congnhan.hoten_cn = thamgia.hoten_cn

join cgtrinh ct2 on ct2.stt_ctr = thamgia.stt_ctr
where  ct2.tinh_thanh = 'can tho' and congnhan.hoten_cn NOT IN (
        select tg1.hoten_cn
        from thamgia tg1
        join cgtrinh cg1 on cg1.stt_ctr = tg1.stt_ctr
        where cg1.tinh_thanh ='vinh long');
--cau 25
select ct1.ten_thau 
from cgtrinh ct1
where ct1.kinh_phi >
(select max(kinh_phi) from cgtrinh where TEN_thau ='phong dich vu so xd');

--cau 26
select hoten_kts from thietke
where thu_lao < (select avg(thu_lao) from thietke); 

--cau 27

select hoten_cn, sum(so_ngay) from thamgia
group by hoten_cn having sum(so_ngay) >
    (select sum(so_ngay) from thamgia
    where HOTEN_CN='nguyen hong van'
    group by hoten_cn);


--cau 28
select hoten_cn 
from thamgia 
group by hoten_cn
having count ( distinct stt_ctr) = (select count(*) from thamgia);


--cau 29

select hoten_cn 
from thamgia 
where stt_ctr in  (
    select stt_ctr from thamgia
    where hoten_cn='nguyen hong van'
    )
group by hoten_cn
having count(distinct stt_ctr) = (SELECT COUNT(DISTINCT STT_CTR) FROM THAMGIA WHERE HOTEN_CN = 'nguyen hong van'
);


-- cau 30
SELECT DISTINCT CT1.TEN_THAU AS THAU_1, CT2.TEN_THAU AS THAU_2, CT1.TINH_THANH
FROM CGTRINH CT1
JOIN CGTRINH CT2 
    ON CT1.TINH_THANH = CT2.TINH_THANH  -- Cùng thành phố
    AND CT1.TEN_THAU < CT2.TEN_THAU;     -- Tránh lặp cặp (A, B) và (B, A)

--cau 31

SELECT TG1.HOTEN_CN AS CN1, TG2.HOTEN_CN AS CN2, COUNT(*) AS SO_CONG_TRINH
FROM THAMGIA TG1
JOIN THAMGIA TG2 
    ON TG1.STT_CTR = TG2.STT_CTR  -- Cùng công trình
    AND TG1.HOTEN_CN < TG2.HOTEN_CN  -- Loại bỏ trùng lặp (A, B) và (B, A)
GROUP BY TG1.HOTEN_CN, TG2.HOTEN_CN
HAVING COUNT(*) >= 2;  -- Ít nhất 2 công trình































