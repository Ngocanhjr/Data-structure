CREATE TABLE DIA_DIEM (
    tenDD VARCHAR2(100) PRIMARY KEY,
    socho NUMBER,
    tpho VARCHAR2(100),
    vung VARCHAR2(100),
    gia NUMBER
);

CREATE TABLE HOAT_DONG (
    tenDD VARCHAR2(100),
    tenHoatDong VARCHAR2(100),
    gia NUMBER
   -- PRIMARY KEY (tenDD, tenHoatDong),
    --FOREIGN KEY (tenDD) REFERENCES DIA_DIEM(tenDD)
);

CREATE TABLE KHACH_HANG (
    idKH NUMBER PRIMARY KEY,
    hoKH VARCHAR2(50),
    tenKH VARCHAR2(50),
    TPho VARCHAR2(100),
    vung VARCHAR2(100)
);

CREATE TABLE KY_NGHI (
    idKH NUMBER,
    tenDD VARCHAR2(100),
    ngayBD DATE,
    ngayKT DATE,
    socho NUMBER,
    CONSTRAINT pk_kynghi PRIMARY KEY (idKH, tenDD, ngayBD),
    CONSTRAINT fk_kynghi_khachhang FOREIGN KEY (idKH) REFERENCES KHACH_HANG(idKH),
    CONSTRAINT fk_kynghi_diadiem FOREIGN KEY (tenDD) REFERENCES DIA_DIEM(tenDD)
);
   
select * from dia_diem;
select * from hoat_dong;
select * from khach_hang; 
select * from ky_nghi;
 
 
 --cau 1
 --thêm khóa chính
 alter table hoat_dong
 add PRIMARY key (TENDD, TENHOATDONG);
 
 --thêm khóa ngoại
alter table hoat_dong
add FOREIGN key (tendd) REFERENCES dia_diem(tendd);
 
 --thêm gàn buộc
 alter table dia_diem
 add UNIQUE (tpho,vung);
 
 --cau 2
 select hokh, tenkh from khach_hang
 where vung= 'Nam';
 
 --cau 3
 
 select dia_diem.vung from
dia_diem join ky_nghi on dia_diem.tendd = ky_nghi.tendd
         join khach_hang on khach_hang.idkh = ky_nghi.idkh 
 where khach_hang.hokh ='Nguyen' and khach_hang.tenkh='An'
 order by khach_hang.tenkh;
 
 
 --cau 4
 
 select dia_diem.tendd, dia_diem.tpho, count(hoat_dong.tenhoatdong) from
 dia_diem join hoat_dong on dia_diem.tendd = hoat_dong.tendd
 group by  dia_diem.tendd, dia_diem.tpho
 having count(hoat_dong.tenhoatdong) >=2;
 
 --cau 5
select khach_hang.tenkh from 
 dia_diem join ky_nghi on dia_diem.tendd = ky_nghi.tendd
          join khach_hang on khach_hang.idkh = ky_nghi.idkh
where  dia_diem.vung = 'Nam'
and khach_hang.idkh not in (
 
 
 select khach_hang.idkh from 
 dia_diem join ky_nghi on dia_diem.tendd = ky_nghi.tendd
          join khach_hang on khach_hang.idkh = ky_nghi.idkh
where dia_diem.vung <> 'Nam');
 

 -- cau  6
 select tendd, count(*) solandi from
 ky_nghi 
 group by tendd
 having count(*)  =(
    select max(solan) from (
        select tendd, count(*) solan from
        ky_nghi 
        group by tendd )
);


 
 --------------------------------------------------------
 
 
 CREATE TABLE DU_AN (
    MA_DU_AN VARCHAR(10) PRIMARY KEY,
    TEN_DU_AN VARCHAR(255),
    THANH_PHO VARCHAR(100)
);

CREATE TABLE HANG_HOA (
    MA_HANG VARCHAR(10) PRIMARY KEY,
    TEN_HANG VARCHAR(255),
    MAU VARCHAR(50),
    TR_LUONG DECIMAL(10,2)
);

CREATE TABLE NHA_CC (
    MA_NCC VARCHAR(10) PRIMARY KEY,
    TEN_NCC VARCHAR(255),
    VON DECIMAL(15,2),
    THANH_PHO VARCHAR(100)
);

CREATE TABLE CUNG_UNG (
    MA_NCC VARCHAR(10),
    MA_HANG VARCHAR(10),
    MA_DU_AN VARCHAR(10),
    SO_LUONG INT,
    --PRIMARY KEY (MA_NCC, MA_HANG, MA_DU_AN),
   -- FOREIGN KEY (MA_NCC) REFERENCES NHA_CC(MA_NCC),
    FOREIGN KEY (MA_HANG) REFERENCES HANG_HOA(MA_HANG),
    FOREIGN KEY (MA_DU_AN) REFERENCES DU_AN(MA_DU_AN)
);

--cau 1
alter table cung_ung
add PRIMARY key (MA_NCC,MA_HANG, MA_DU_AN);
 
alter table cung_ung
add FOREIGN KEY (MA_NCC) REFERENCES NHA_CC(MA_NCC);
 
 
 alter table hang_hoa
 add check (mau in('xam', 'do', 'trang', 'xanh'));
 
 --
 
select * from du_an;
select * from hang_hoa;
select * from nha_cc;
select * from cung_ung;
 

--cau 2
select * from hang_hoa
where mau ='xanh';
 
--cau 4
select nha_cc.ten_ncc ,hang_hoa.ten_hang, count(*) soduan from
cung_ung join hang_hoa on cung_ung.ma_hang = cung_ung.ma_hang
         join nha_cc on nha_cc.ma_ncc = cung_ung.ma_ncc
group by nha_cc.ten_ncc ,hang_hoa.ten_hang
having count(*) >= 2;
 
 --cau 3
select nha_cc.ten_ncc from
cung_ung join du_an on cung_ung.ma_du_an = du_an.ma_du_an
         join hang_hoa on hang_hoa.ma_hang = cung_ung.ma_hang
         join nha_cc on  nha_cc.ma_ncc = cung_ung.ma_ncc
 where du_an.ten_du_an ='Tân Long'
order by nha_cc.ten_ncc ;
 
 --cau 5
select nha_cc.ten_ncc from
cung_ung join hang_hoa on hang_hoa.ma_hang = cung_ung.ma_hang
         join nha_cc ON  nha_cc.ma_ncc = cung_ung.ma_ncc
 where hang_hoa.mau ='trang'
and nha_cc.ma_ncc not in(
select distinct cung_ung.ma_ncc from
cung_ung join hang_hoa on hang_hoa.ma_hang = cung_ung.ma_hang
where hang_hoa.mau <> 'trang');
 
 --cau 6
 select nha_cc.ten_ncc,count(hang_hoa.ma_hang)soluongmathang from
cung_ung join hang_hoa on hang_hoa.ma_hang = cung_ung.ma_hang
         join nha_cc ON  nha_cc.ma_ncc = cung_ung.ma_ncc      
group by nha_cc.ten_ncc
having count(hang_hoa.ma_hang) = (
        select max(soluongmathang) from (
            select nha_cc.ten_ncc,count(hang_hoa.ma_hang)soluongmathang from
            cung_ung join hang_hoa on hang_hoa.ma_hang = cung_ung.ma_hang
                     join nha_cc ON  nha_cc.ma_ncc = cung_ung.ma_ncc      
            group by nha_cc.ten_ncc
            )
        );
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
   
   
   