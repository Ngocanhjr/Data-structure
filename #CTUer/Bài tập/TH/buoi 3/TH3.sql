--câu 1
select * from tacpham;
select * from docgia;
select * from sach;
select * from muon;

--cau 2


-- cau 3
select nt,tua from tacpham
where tacgia ='Guy de Maupassant';

-- cau 4
select * from docgia
where dchi = '32 rue des Alouettes, 75003 Paris';

-- cau 5
select NXB from
tacpham join sach on tacpham.nt = sach.nt
where tua like '%leurs%';

--cau 6
select tua from tacpham
where tua like '%Le%';

--cau 7
select ho, ten from
docgia join muon on docgia.nd = muon.nd
where muon.ngaymuon between TO_DATE('15-09-2007','DD-MM-YYYY')
                        and TO_DATE('20-09-2007','DD-MM-YYYY');
                        
--cau 8
select DISTINCT nxb from
tacpham join sach on tacpham.nt = sach.nt
where tua = 'Germinal ';

--cau 10
select docgia.ten from
tacpham join sach on tacpham.nt = sach.ns
        join muon on muon.ns = sach.ns
        join docgia on docgia.nd = muon.nd
where tacpham.tua = 'Les Fleurs du mal';

-- cau 9
select docgia.ten from
tacpham join sach on tacpham.nt = sach.ns
        join muon on muon.ns = sach.ns
        join docgia on docgia.nd = muon.nd
where tacpham.tua = 'Poï¿½e';

--cau 11
select tacpham.tua,docgia.ten tenDocGia from
tacpham join sach on tacpham.nt = sach.nt
        join muon on muon.ns = sach.ns
        join docgia on docgia.nd = muon.nd
where muon.ngaytra > muon.hantra;

-- cau 12
select tacpham.tua,docgia.ten tenDocGia from
tacpham join sach on tacpham.nt = sach.nt
        join muon on muon.ns = sach.ns
        join docgia on docgia.nd = muon.nd
where muon.ngaytra < muon.hantra;

--câu 13
select DISTINCT docgia.ten tenDocGia from
tacpham join sach on tacpham.nt = sach.nt
        join muon on muon.ns = sach.ns
        join docgia on docgia.nd = muon.nd
where tacpham.tacgia ='Victor Hugo';

--cau 14
select DISTINCT docgia.ten tenDocGia, tacpham.tua from
tacpham join sach on tacpham.nt = sach.nt
        join muon on muon.ns = sach.ns
        join docgia on docgia.nd = muon.nd
where EXTRACT (YEAR from muon.ngaymuon) = 2007;

--cau 15
select count(*) from tacpham ;

--cau 16
select tacpham.tua, count(sach.ns)soluong from
tacpham join sach on tacpham.nt = sach.nt
 GROUP BY tacpham.tua;

--cau 17
select tacpham.tua, count(sach.ns)soluong   from
tacpham join sach on tacpham.nt = sach.nt
 GROUP BY tacpham.tua having count(sach.ns) >=2;

--cau 18
select tacgia, count(tua) from tacpham GROUP BY tacgia;

--cau 19

select tacgia, count(tua) from tacpham GROUP BY tacgia HAVING count(tua) >=2;

--cau 20
select docgia.ten, extract(year from muon.ngaymuon), count(*) from 
docgia join muon on docgia.nd = muon.nd
Group BY docgia.ten  ,extract(year from muon.ngaymuon)
ORDER BY  extract(year from muon.ngaymuon),count(*);

-- cau 21
select tacpham.tua, count(sach.ns)soluong   from
tacpham join sach on tacpham.nt = sach.nt
 GROUP BY tacpham.tua having count(sach.ns) >=3;

--cau 22
CREATE TABLE C22 AS 
select tacpham.tua, count(sach.ns) sosach from
tacpham join sach on tacpham.nt = sach.nt
 GROUP BY tacpham.tua;
 
 select * from c22 
 where  sosach=( select max(sosach) from c22);
 drop table c22;
 

-- cau 23
create table  c23 as
select sach.nxb, count(sach.ns) soluongsach from
sach
group by sach.nxb;

select * from c23
where soluongsach = (select max(soluongsach) from c23);
DROP table c23;


--cau 24
create table  c24 as
select tacpham.tua, count(sach.ns) soluongsachmuon from
sach join tacpham on sach.nt = tacpham.nt
     join muon on muon.ns = muon.ns
group by tacpham.tua;

select * from c24
where soluongsachmuon = (select max(soluongsachmuon) from c24);
DROP table c24;

--cau 25

create table  c25 as
select tacpham.tua, count(sach.ns) soluongsachmuon from
sach join tacpham on sach.nt = tacpham.nt
     join muon on muon.ns = muon.ns
group by tacpham.tua;

select * from c25
where soluongsachmuon = (select MIN(soluongsachmuon) from c25);
DROP table c25;

-- cau 26
create table c26 as
select docgia.ten, count(muon.ns) solanmuonsach from
docgia join muon on docgia.nd = muon.nd
group by docgia.ten ;

select * from c26
where solanmuonsach = (select max(solanmuonsach) from c26);

drop table c26;

--cau 27

create table c27 as
select docgia.ten, count(muon.ns) solanmuonsach from
docgia join muon on docgia.nd = muon.nd
group by docgia.ten ;

select * from c27
where solanmuonsach = (select min(solanmuonsach) from c27);

drop table c27;

--cau 28
select distinct tacpham.tua from
tacpham join sach on tacpham.nt = sach.nt
        left join muon on muon.ns = sach.ns
where muon.ngaymuon is null;

--cau 29

select distinct tacpham.tua from
tacpham join sach on tacpham.nt = sach.nt
        left join muon on muon.ns = sach.ns
group by tacpham.tua having count(sach.ns) = count(muon.ns);

--cau 30
select distinct docgia.ten from
docgia left join muon on docgia.nd = muon.nd
where muon.nd is null;

-- cau 31

select sach.ns, sach.nxb from
sach left join muon on sach.ns = muon.ns
where muon.nd is null;


















































