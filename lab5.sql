--create tables
CREATE table stuInfo(
	SNO integer primary key,
	SName varchar(10) not NULL ,
	SCLASS varchar(20) 
);

CREATE table schoolCard(
	CNO integer,
	SNO integer not NULL,
	CardDate date,
	remainingSum integer,
    primary key(CNO), 
    foregin key (SNO) references stuInfo
);

CREATE table serviceWindows(
	serviceWNO integer primary key,
	serviceWName varchar(20),
	serviceWAdmin varchar(10),
	serviceWATele char(13)
);

CREATE table foodConsume(
	consumeID integer primary key,
	CNO integer not NULL,
	serviceWNO integer not NULL,
	consumeDate date,
	amount integer,
    foregin key(CNO) references schoolCard
);
--create index & alter table

create index amount_index on foodconsume (amount desc);
alter table stuInfo add column MobilePhone char(13); 

--query sentences

select sno, sname, sclass from stuinfo where sclass = 'SoftWare165';
select cno, sname, carddate, remainingsum from schoolcard natural join stuinfo where remainingsum < 15;

--
insert into stuInfo(sno, sname, sclass, mobilephone) values(19307110, '王艺坤', '20CS', '19121764250');
insert into schoolcard(cno, sno, remainingsum) values(1, 19307110, 5);

--
delete from schoolcard where remainingsum < 15;

select cno, count(amount) as tot from foodconsume 
where cno in ('201707', '201611', '201512') group by cno order by tot desc;  

select cno, sno, 
case 
	when remainingsum >= 200
		then '余额充足'
	when remainingsum >= 15
		then '正常'
	else '待充值'
end status
from schoolcard;


create view V_consumeInfo as
	select cno, sname, servicewname, consumedate, amount
	from foodconsume natural join schoolcard natural join stuInfo natural join servicewindows;





