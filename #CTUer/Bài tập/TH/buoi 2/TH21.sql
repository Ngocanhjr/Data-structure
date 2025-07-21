--câu 1
select * from KHOAHOC;

-- câu 2
select * from HOCVIEN
WHERE GIOITINH = '1';

-- cau 3
SELECT * FROM hocvien
WHERE diachi like '%Cần Thơ%';

-- cau 4
SELECT * FROM khoahoc k, lop l
where k.makh = l.makh  and tenkh = 'Khóa 1';
/*SELECT * FROM khoahoc 
where  TENKH = 'Khóa 1';
select * from LOP
where TENKH = 'Khóa 1';*/

--cau 5
SELECT H.MAHV, TENHV
FROM KHOAHOC K JOIN LOP L ON K.MAKH=L.MAKH 
        JOIN PHIEUTHU P ON P.MALOP=L.MALOP
        JOIN HOCVIEN H ON H.MAHV=P.MAHV
WHERE TENKH='Khóa 1';

select h.MAHV , TENHV
FROM khoahoc k JOIN lop l on k.makh = l.makh
        join phieuthu p on p.malop = l.malop
        join hocvien h on h.mahv = p.mahv
where tenkh = 'Khóa 1';

--cau 6
Select h.tenhv from hocvien h
where tenhv like '%Đỗ%';

-- cau 7
 select * from HOCVIEN
 where EXTRACT (YEAR from NGAYSINH) = 2000;
 
 --cau 8
  select * from HOCVIEN
 where EXTRACT (YEAR from NGAYSINH) = 2001
 and EXTRACT(MONTH from NGAYSINH) = 12;
 
 -- cau 9
 select * from HOCVIEN
 where EXTRACT ( YEAR from NGAYSINH) BETWEEN 1988 and 2000;
 
 --cau 10
 select * from phieuthu
 where EXTRACT (year from ngaylapphieu) = 2021
 and EXTRACT (month from ngaylapphieu) = 6
 and EXTRACT (day from ngaylapphieu) BETWEEN 5 and 10;
 
 --cau 11
 select TENHV
 from  LOAILOP LL join LOP L on ll.maloai = l.maloai
        join phieuthu P on p.malop = l.malop
        join hocvien H on h.mahv = p.mahv
where TEnLOP= 'Lớp 1' and lower(tenloai)='tiếng anh căn bản';
 
 -- cau 12
 select * from KHOAHOC;
 select * from CHUONGTRINH;
 select * from LOP;
 select * from LOAILOP;
  select * from hocvien;
 
 select L.tenlop,CT.tenct
 from CHUONGTRINH CT join LOAILOP LL on ct.mact = ll.mact
        join LOP L on l.maloai = ll.maloai
where ct.tenct = 'Tiếng Anh Tổng Quát';
 
 --cau 13
select *
FROM chuongtrinh CT join loailop LL on ct.mact = LL.mact
                    join lop L on l.maloai = ll.maloai
                    join phieuthu PT on pt.malop = l.malop
                    join hocvien HV on hv.mahv = pt.mahv
where l.tenlop = 'Lớp 1' and ll.tenloai = 'Tiếng Anh A1';
 
 -- câu 14
select hv.tenhv, mh.tenmh, d.diem
FROM diem D join monhoc MH on d.mamh = mh.mamh
            join hocvien HV on hv.mahv = d.mahv
            JOIN PHIEUTHU PT ON PT.MAHV = HV.MAHV
            join lop L on l.malop = pt.malop
            join khoahoc KH on KH.makh = l.makh
where kh.tenkh= 'Khóa 1';
 
 -- câu 15
 -- có as hay ko cũng được
 SELECT COUNT(*) as TongSoHocVien FROM HOCVIEN;

--cau 16
SELECT count(*) sohvlop1
from Loailop LL join lop L on ll.maloai = l.maloai
                join phieuthu PT on pt.malop = l.malop
                join hocvien HV on hv.mahv = pt.mahv
where l.tenlop = 'Lớp 1' and ll.tenloai = 'Tiếng Anh căn bản';
 
 
 --cau 17
 select  sum(phieuthu.thanhtien) as tongtien from
 loailop join lop on loailop.maloai = lop.maloai
        join phieuthu on phieuthu.malop = lop.malop
 where loailop.tenloai = 'Tiếng Anh căn bản' and lop.tenlop = 'Lớp 1';
 
 -- cau 18
select sum(phieuthu.thanhtien) tongTienThu from
khoahoc join lop on khoahoc.makh = lop.makh
        join phieuthu on phieuthu.malop = lop.malop
where khoahoc.tenkh = 'Khóa 1';

--cau 19
select AVG(diem.diem) as diemTB from 
hocvien join diem on hocvien.mahv = diem.mahv
        join lop on lop.malop = diem.malop
        join loailop on loailop.maloai = lop.maloai
where hocvien.tenhv = 'Đỗ Gia Bảo' and hocvien.ngaysinh ='2001-12-02' and lop.tenlop ='Lớp 1' and loailop.tenloai ='Tiếng Anh căn bản';
 
 --cau 20
 SELECT MAX(DIEM) DIEMLONNHAT
FROM DIEM;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 