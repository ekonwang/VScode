
main:     file format elf64-x86-64


Disassembly of section .interp:

0000000000000238 <.interp>:
 238:	2f                   	(bad)  
 239:	6c                   	insb   (%dx),%es:(%rdi)
 23a:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
 241:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
 246:	78 2d                	js     275 <_init-0x443>
 248:	78 38                	js     282 <_init-0x436>
 24a:	36 2d 36 34 2e 73    	ss sub $0x732e3436,%eax
 250:	6f                   	outsl  %ds:(%rsi),(%dx)
 251:	2e 32 00             	xor    %cs:(%rax),%al

Disassembly of section .note.ABI-tag:

0000000000000254 <.note.ABI-tag>:
 254:	04 00                	add    $0x0,%al
 256:	00 00                	add    %al,(%rax)
 258:	10 00                	adc    %al,(%rax)
 25a:	00 00                	add    %al,(%rax)
 25c:	01 00                	add    %eax,(%rax)
 25e:	00 00                	add    %al,(%rax)
 260:	47                   	rex.RXB
 261:	4e 55                	rex.WRX push %rbp
 263:	00 00                	add    %al,(%rax)
 265:	00 00                	add    %al,(%rax)
 267:	00 03                	add    %al,(%rbx)
 269:	00 00                	add    %al,(%rax)
 26b:	00 02                	add    %al,(%rdx)
 26d:	00 00                	add    %al,(%rax)
 26f:	00 00                	add    %al,(%rax)
 271:	00 00                	add    %al,(%rax)
	...

Disassembly of section .note.gnu.build-id:

0000000000000274 <.note.gnu.build-id>:
 274:	04 00                	add    $0x0,%al
 276:	00 00                	add    %al,(%rax)
 278:	14 00                	adc    $0x0,%al
 27a:	00 00                	add    %al,(%rax)
 27c:	03 00                	add    (%rax),%eax
 27e:	00 00                	add    %al,(%rax)
 280:	47                   	rex.RXB
 281:	4e 55                	rex.WRX push %rbp
 283:	00 fc                	add    %bh,%ah
 285:	73 68                	jae    2ef <_init-0x3c9>
 287:	e3 64                	jrcxz  2ed <_init-0x3cb>
 289:	33 48 4b             	xor    0x4b(%rax),%ecx
 28c:	12 e8                	adc    %al,%ch
 28e:	82                   	(bad)  
 28f:	04 66                	add    $0x66,%al
 291:	c6                   	(bad)  
 292:	f2 f4                	repnz hlt 
 294:	1d                   	.byte 0x1d
 295:	a4                   	movsb  %ds:(%rsi),%es:(%rdi)
 296:	98                   	cwtl   
 297:	c0                   	.byte 0xc0

Disassembly of section .gnu.hash:

0000000000000298 <.gnu.hash>:
 298:	01 00                	add    %eax,(%rax)
 29a:	00 00                	add    %al,(%rax)
 29c:	01 00                	add    %eax,(%rax)
 29e:	00 00                	add    %al,(%rax)
 2a0:	01 00                	add    %eax,(%rax)
	...

Disassembly of section .dynsym:

00000000000002b8 <.dynsym>:
	...
 2d0:	3b 00                	cmp    (%rax),%eax
 2d2:	00 00                	add    %al,(%rax)
 2d4:	12 00                	adc    (%rax),%al
	...
 2e6:	00 00                	add    %al,(%rax)
 2e8:	8b 00                	mov    (%rax),%eax
 2ea:	00 00                	add    %al,(%rax)
 2ec:	20 00                	and    %al,(%rax)
	...
 2fe:	00 00                	add    %al,(%rax)
 300:	20 00                	and    %al,(%rax)
 302:	00 00                	add    %al,(%rax)
 304:	12 00                	adc    (%rax),%al
	...
 316:	00 00                	add    %al,(%rax)
 318:	2a 00                	sub    (%rax),%al
 31a:	00 00                	add    %al,(%rax)
 31c:	12 00                	adc    (%rax),%al
	...
 32e:	00 00                	add    %al,(%rax)
 330:	43 00 00             	rex.XB add %al,(%r8)
 333:	00 12                	add    %dl,(%rdx)
	...
 345:	00 00                	add    %al,(%rax)
 347:	00 59 00             	add    %bl,0x0(%rcx)
 34a:	00 00                	add    %al,(%rax)
 34c:	12 00                	adc    (%rax),%al
	...
 35e:	00 00                	add    %al,(%rax)
 360:	0b 00                	or     (%rax),%eax
 362:	00 00                	add    %al,(%rax)
 364:	12 00                	adc    (%rax),%al
	...
 376:	00 00                	add    %al,(%rax)
 378:	a7                   	cmpsl  %es:(%rdi),%ds:(%rsi)
 379:	00 00                	add    %al,(%rax)
 37b:	00 20                	add    %ah,(%rax)
	...
 38d:	00 00                	add    %al,(%rax)
 38f:	00 25 00 00 00 12    	add    %ah,0x12000000(%rip)        # 12000395 <_end+0x11dfe37d>
	...
 3a5:	00 00                	add    %al,(%rax)
 3a7:	00 11                	add    %dl,(%rcx)
 3a9:	00 00                	add    %al,(%rax)
 3ab:	00 12                	add    %dl,(%rdx)
	...
 3bd:	00 00                	add    %al,(%rax)
 3bf:	00 b6 00 00 00 20    	add    %dh,0x20000000(%rsi)
	...
 3d5:	00 00                	add    %al,(%rax)
 3d7:	00 4a 00             	add    %cl,0x0(%rdx)
 3da:	00 00                	add    %al,(%rax)
 3dc:	22 00                	and    (%rax),%al
	...
 3ee:	00 00                	add    %al,(%rax)
 3f0:	0c 00                	or     $0x0,%al
 3f2:	00 00                	add    %al,(%rax)
 3f4:	12 00                	adc    (%rax),%al
	...

Disassembly of section .dynstr:

0000000000000408 <.dynstr>:
 408:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
 40c:	63 2e                	movslq (%rsi),%ebp
 40e:	73 6f                	jae    47f <_init-0x239>
 410:	2e 36 00 73 72       	cs add %dh,%ss:0x72(%rbx)
 415:	61                   	(bad)  
 416:	6e                   	outsb  %ds:(%rsi),(%dx)
 417:	64 00 5f 5f          	add    %bl,%fs:0x5f(%rdi)
 41b:	69 73 6f 63 39 39 5f 	imul   $0x5f393963,0x6f(%rbx),%esi
 422:	73 63                	jae    487 <_init-0x231>
 424:	61                   	(bad)  
 425:	6e                   	outsb  %ds:(%rsi),(%dx)
 426:	66 00 70 75          	data16 add %dh,0x75(%rax)
 42a:	74 73                	je     49f <_init-0x219>
 42c:	00 74 69 6d          	add    %dh,0x6d(%rcx,%rbp,2)
 430:	65 00 5f 5f          	add    %bl,%gs:0x5f(%rdi)
 434:	73 74                	jae    4aa <_init-0x20e>
 436:	61                   	(bad)  
 437:	63 6b 5f             	movslq 0x5f(%rbx),%ebp
 43a:	63 68 6b             	movslq 0x6b(%rax),%ebp
 43d:	5f                   	pop    %rdi
 43e:	66 61                	data16 (bad) 
 440:	69 6c 00 70 75 74 63 	imul   $0x68637475,0x70(%rax,%rax,1),%ebp
 447:	68 
 448:	61                   	(bad)  
 449:	72 00                	jb     44b <_init-0x26d>
 44b:	70 72                	jo     4bf <_init-0x1f9>
 44d:	69 6e 74 66 00 5f 5f 	imul   $0x5f5f0066,0x74(%rsi),%ebp
 454:	63 78 61             	movslq 0x61(%rax),%edi
 457:	5f                   	pop    %rdi
 458:	66 69 6e 61 6c 69    	imul   $0x696c,0x61(%rsi),%bp
 45e:	7a 65                	jp     4c5 <_init-0x1f3>
 460:	00 5f 5f             	add    %bl,0x5f(%rdi)
 463:	6c                   	insb   (%dx),%es:(%rdi)
 464:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
 46b:	72 74                	jb     4e1 <_init-0x1d7>
 46d:	5f                   	pop    %rdi
 46e:	6d                   	insl   (%dx),%es:(%rdi)
 46f:	61                   	(bad)  
 470:	69 6e 00 47 4c 49 42 	imul   $0x42494c47,0x0(%rsi),%ebp
 477:	43 5f                	rex.XB pop %r15
 479:	32 2e                	xor    (%rsi),%ch
 47b:	37                   	(bad)  
 47c:	00 47 4c             	add    %al,0x4c(%rdi)
 47f:	49                   	rex.WB
 480:	42                   	rex.X
 481:	43 5f                	rex.XB pop %r15
 483:	32 2e                	xor    (%rsi),%ch
 485:	34 00                	xor    $0x0,%al
 487:	47                   	rex.RXB
 488:	4c                   	rex.WR
 489:	49                   	rex.WB
 48a:	42                   	rex.X
 48b:	43 5f                	rex.XB pop %r15
 48d:	32 2e                	xor    (%rsi),%ch
 48f:	32 2e                	xor    (%rsi),%ch
 491:	35 00 5f 49 54       	xor    $0x54495f00,%eax
 496:	4d 5f                	rex.WRB pop %r15
 498:	64 65 72 65          	fs gs jb 501 <_init-0x1b7>
 49c:	67 69 73 74 65 72 54 	imul   $0x4d547265,0x74(%ebx),%esi
 4a3:	4d 
 4a4:	43 6c                	rex.XB insb (%dx),%es:(%rdi)
 4a6:	6f                   	outsl  %ds:(%rsi),(%dx)
 4a7:	6e                   	outsb  %ds:(%rsi),(%dx)
 4a8:	65 54                	gs push %rsp
 4aa:	61                   	(bad)  
 4ab:	62                   	(bad)  
 4ac:	6c                   	insb   (%dx),%es:(%rdi)
 4ad:	65 00 5f 5f          	add    %bl,%gs:0x5f(%rdi)
 4b1:	67 6d                	insl   (%dx),%es:(%edi)
 4b3:	6f                   	outsl  %ds:(%rsi),(%dx)
 4b4:	6e                   	outsb  %ds:(%rsi),(%dx)
 4b5:	5f                   	pop    %rdi
 4b6:	73 74                	jae    52c <_init-0x18c>
 4b8:	61                   	(bad)  
 4b9:	72 74                	jb     52f <_init-0x189>
 4bb:	5f                   	pop    %rdi
 4bc:	5f                   	pop    %rdi
 4bd:	00 5f 49             	add    %bl,0x49(%rdi)
 4c0:	54                   	push   %rsp
 4c1:	4d 5f                	rex.WRB pop %r15
 4c3:	72 65                	jb     52a <_init-0x18e>
 4c5:	67 69 73 74 65 72 54 	imul   $0x4d547265,0x74(%ebx),%esi
 4cc:	4d 
 4cd:	43 6c                	rex.XB insb (%dx),%es:(%rdi)
 4cf:	6f                   	outsl  %ds:(%rsi),(%dx)
 4d0:	6e                   	outsb  %ds:(%rsi),(%dx)
 4d1:	65 54                	gs push %rsp
 4d3:	61                   	(bad)  
 4d4:	62                   	.byte 0x62
 4d5:	6c                   	insb   (%dx),%es:(%rdi)
 4d6:	65                   	gs
	...

Disassembly of section .gnu.version:

00000000000004d8 <.gnu.version>:
 4d8:	00 00                	add    %al,(%rax)
 4da:	02 00                	add    (%rax),%al
 4dc:	00 00                	add    %al,(%rax)
 4de:	02 00                	add    (%rax),%al
 4e0:	03 00                	add    (%rax),%eax
 4e2:	02 00                	add    (%rax),%al
 4e4:	02 00                	add    (%rax),%al
 4e6:	02 00                	add    (%rax),%al
 4e8:	00 00                	add    %al,(%rax)
 4ea:	02 00                	add    (%rax),%al
 4ec:	04 00                	add    $0x0,%al
 4ee:	00 00                	add    %al,(%rax)
 4f0:	02 00                	add    (%rax),%al
 4f2:	02 00                	add    (%rax),%al

Disassembly of section .gnu.version_r:

00000000000004f8 <.gnu.version_r>:
 4f8:	01 00                	add    %eax,(%rax)
 4fa:	03 00                	add    (%rax),%eax
 4fc:	01 00                	add    %eax,(%rax)
 4fe:	00 00                	add    %al,(%rax)
 500:	10 00                	adc    %al,(%rax)
 502:	00 00                	add    %al,(%rax)
 504:	00 00                	add    %al,(%rax)
 506:	00 00                	add    %al,(%rax)
 508:	17                   	(bad)  
 509:	69 69 0d 00 00 04 00 	imul   $0x40000,0xd(%rcx),%ebp
 510:	6b 00 00             	imul   $0x0,(%rax),%eax
 513:	00 10                	add    %dl,(%rax)
 515:	00 00                	add    %al,(%rax)
 517:	00 14 69             	add    %dl,(%rcx,%rbp,2)
 51a:	69 0d 00 00 03 00 75 	imul   $0x75,0x30000(%rip),%ecx        # 30524 <__FRAME_END__+0x2f618>
 521:	00 00 00 
 524:	10 00                	adc    %al,(%rax)
 526:	00 00                	add    %al,(%rax)
 528:	75 1a                	jne    544 <_init-0x174>
 52a:	69 09 00 00 02 00    	imul   $0x20000,(%rcx),%ecx
 530:	7f 00                	jg     532 <_init-0x186>
 532:	00 00                	add    %al,(%rax)
 534:	00 00                	add    %al,(%rax)
	...

Disassembly of section .rela.dyn:

0000000000000538 <.rela.dyn>:
 538:	80 1d 20 00 00 00 00 	sbbb   $0x0,0x20(%rip)        # 55f <_init-0x159>
 53f:	00 08                	add    %cl,(%rax)
 541:	00 00                	add    %al,(%rax)
 543:	00 00                	add    %al,(%rax)
 545:	00 00                	add    %al,(%rax)
 547:	00 70 08             	add    %dh,0x8(%rax)
 54a:	00 00                	add    %al,(%rax)
 54c:	00 00                	add    %al,(%rax)
 54e:	00 00                	add    %al,(%rax)
 550:	88 1d 20 00 00 00    	mov    %bl,0x20(%rip)        # 576 <_init-0x142>
 556:	00 00                	add    %al,(%rax)
 558:	08 00                	or     %al,(%rax)
 55a:	00 00                	add    %al,(%rax)
 55c:	00 00                	add    %al,(%rax)
 55e:	00 00                	add    %al,(%rax)
 560:	30 08                	xor    %cl,(%rax)
 562:	00 00                	add    %al,(%rax)
 564:	00 00                	add    %al,(%rax)
 566:	00 00                	add    %al,(%rax)
 568:	08 20                	or     %ah,(%rax)
 56a:	20 00                	and    %al,(%rax)
 56c:	00 00                	add    %al,(%rax)
 56e:	00 00                	add    %al,(%rax)
 570:	08 00                	or     %al,(%rax)
 572:	00 00                	add    %al,(%rax)
 574:	00 00                	add    %al,(%rax)
 576:	00 00                	add    %al,(%rax)
 578:	08 20                	or     %ah,(%rax)
 57a:	20 00                	and    %al,(%rax)
 57c:	00 00                	add    %al,(%rax)
 57e:	00 00                	add    %al,(%rax)
 580:	d8 1f                	fcomps (%rdi)
 582:	20 00                	and    %al,(%rax)
 584:	00 00                	add    %al,(%rax)
 586:	00 00                	add    %al,(%rax)
 588:	06                   	(bad)  
 589:	00 00                	add    %al,(%rax)
 58b:	00 02                	add    %al,(%rdx)
	...
 595:	00 00                	add    %al,(%rax)
 597:	00 e0                	add    %ah,%al
 599:	1f                   	(bad)  
 59a:	20 00                	and    %al,(%rax)
 59c:	00 00                	add    %al,(%rax)
 59e:	00 00                	add    %al,(%rax)
 5a0:	06                   	(bad)  
 5a1:	00 00                	add    %al,(%rax)
 5a3:	00 06                	add    %al,(%rsi)
	...
 5ad:	00 00                	add    %al,(%rax)
 5af:	00 e8                	add    %ch,%al
 5b1:	1f                   	(bad)  
 5b2:	20 00                	and    %al,(%rax)
 5b4:	00 00                	add    %al,(%rax)
 5b6:	00 00                	add    %al,(%rax)
 5b8:	06                   	(bad)  
 5b9:	00 00                	add    %al,(%rax)
 5bb:	00 08                	add    %cl,(%rax)
	...
 5c5:	00 00                	add    %al,(%rax)
 5c7:	00 f0                	add    %dh,%al
 5c9:	1f                   	(bad)  
 5ca:	20 00                	and    %al,(%rax)
 5cc:	00 00                	add    %al,(%rax)
 5ce:	00 00                	add    %al,(%rax)
 5d0:	06                   	(bad)  
 5d1:	00 00                	add    %al,(%rax)
 5d3:	00 0b                	add    %cl,(%rbx)
	...
 5dd:	00 00                	add    %al,(%rax)
 5df:	00 f8                	add    %bh,%al
 5e1:	1f                   	(bad)  
 5e2:	20 00                	and    %al,(%rax)
 5e4:	00 00                	add    %al,(%rax)
 5e6:	00 00                	add    %al,(%rax)
 5e8:	06                   	(bad)  
 5e9:	00 00                	add    %al,(%rax)
 5eb:	00 0c 00             	add    %cl,(%rax,%rax,1)
	...

Disassembly of section .rela.plt:

00000000000005f8 <.rela.plt>:
 5f8:	98                   	cwtl   
 5f9:	1f                   	(bad)  
 5fa:	20 00                	and    %al,(%rax)
 5fc:	00 00                	add    %al,(%rax)
 5fe:	00 00                	add    %al,(%rax)
 600:	07                   	(bad)  
 601:	00 00                	add    %al,(%rax)
 603:	00 01                	add    %al,(%rcx)
	...
 60d:	00 00                	add    %al,(%rax)
 60f:	00 a0 1f 20 00 00    	add    %ah,0x201f(%rax)
 615:	00 00                	add    %al,(%rax)
 617:	00 07                	add    %al,(%rdi)
 619:	00 00                	add    %al,(%rax)
 61b:	00 03                	add    %al,(%rbx)
	...
 625:	00 00                	add    %al,(%rax)
 627:	00 a8 1f 20 00 00    	add    %ch,0x201f(%rax)
 62d:	00 00                	add    %al,(%rax)
 62f:	00 07                	add    %al,(%rdi)
 631:	00 00                	add    %al,(%rax)
 633:	00 04 00             	add    %al,(%rax,%rax,1)
	...
 63e:	00 00                	add    %al,(%rax)
 640:	b0 1f                	mov    $0x1f,%al
 642:	20 00                	and    %al,(%rax)
 644:	00 00                	add    %al,(%rax)
 646:	00 00                	add    %al,(%rax)
 648:	07                   	(bad)  
 649:	00 00                	add    %al,(%rax)
 64b:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 651 <_init-0x67>
 651:	00 00                	add    %al,(%rax)
 653:	00 00                	add    %al,(%rax)
 655:	00 00                	add    %al,(%rax)
 657:	00 b8 1f 20 00 00    	add    %bh,0x201f(%rax)
 65d:	00 00                	add    %al,(%rax)
 65f:	00 07                	add    %al,(%rdi)
 661:	00 00                	add    %al,(%rax)
 663:	00 07                	add    %al,(%rdi)
	...
 66d:	00 00                	add    %al,(%rax)
 66f:	00 c0                	add    %al,%al
 671:	1f                   	(bad)  
 672:	20 00                	and    %al,(%rax)
 674:	00 00                	add    %al,(%rax)
 676:	00 00                	add    %al,(%rax)
 678:	07                   	(bad)  
 679:	00 00                	add    %al,(%rax)
 67b:	00 09                	add    %cl,(%rcx)
	...
 685:	00 00                	add    %al,(%rax)
 687:	00 c8                	add    %cl,%al
 689:	1f                   	(bad)  
 68a:	20 00                	and    %al,(%rax)
 68c:	00 00                	add    %al,(%rax)
 68e:	00 00                	add    %al,(%rax)
 690:	07                   	(bad)  
 691:	00 00                	add    %al,(%rax)
 693:	00 0a                	add    %cl,(%rdx)
	...
 69d:	00 00                	add    %al,(%rax)
 69f:	00 d0                	add    %dl,%al
 6a1:	1f                   	(bad)  
 6a2:	20 00                	and    %al,(%rax)
 6a4:	00 00                	add    %al,(%rax)
 6a6:	00 00                	add    %al,(%rax)
 6a8:	07                   	(bad)  
 6a9:	00 00                	add    %al,(%rax)
 6ab:	00 0d 00 00 00 00    	add    %cl,0x0(%rip)        # 6b1 <_init-0x7>
 6b1:	00 00                	add    %al,(%rax)
 6b3:	00 00                	add    %al,(%rax)
 6b5:	00 00                	add    %al,(%rax)
	...

Disassembly of section .init:

00000000000006b8 <_init>:
 6b8:	48 83 ec 08          	sub    $0x8,%rsp
 6bc:	48 8b 05 25 19 20 00 	mov    0x201925(%rip),%rax        # 201fe8 <__gmon_start__>
 6c3:	48 85 c0             	test   %rax,%rax
 6c6:	74 02                	je     6ca <_init+0x12>
 6c8:	ff d0                	callq  *%rax
 6ca:	48 83 c4 08          	add    $0x8,%rsp
 6ce:	c3                   	retq   

Disassembly of section .plt:

00000000000006d0 <.plt>:
 6d0:	ff 35 b2 18 20 00    	pushq  0x2018b2(%rip)        # 201f88 <_GLOBAL_OFFSET_TABLE_+0x8>
 6d6:	ff 25 b4 18 20 00    	jmpq   *0x2018b4(%rip)        # 201f90 <_GLOBAL_OFFSET_TABLE_+0x10>
 6dc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000000006e0 <putchar@plt>:
 6e0:	ff 25 b2 18 20 00    	jmpq   *0x2018b2(%rip)        # 201f98 <putchar@GLIBC_2.2.5>
 6e6:	68 00 00 00 00       	pushq  $0x0
 6eb:	e9 e0 ff ff ff       	jmpq   6d0 <.plt>

00000000000006f0 <puts@plt>:
 6f0:	ff 25 aa 18 20 00    	jmpq   *0x2018aa(%rip)        # 201fa0 <puts@GLIBC_2.2.5>
 6f6:	68 01 00 00 00       	pushq  $0x1
 6fb:	e9 d0 ff ff ff       	jmpq   6d0 <.plt>

0000000000000700 <__stack_chk_fail@plt>:
 700:	ff 25 a2 18 20 00    	jmpq   *0x2018a2(%rip)        # 201fa8 <__stack_chk_fail@GLIBC_2.4>
 706:	68 02 00 00 00       	pushq  $0x2
 70b:	e9 c0 ff ff ff       	jmpq   6d0 <.plt>

0000000000000710 <printf@plt>:
 710:	ff 25 9a 18 20 00    	jmpq   *0x20189a(%rip)        # 201fb0 <printf@GLIBC_2.2.5>
 716:	68 03 00 00 00       	pushq  $0x3
 71b:	e9 b0 ff ff ff       	jmpq   6d0 <.plt>

0000000000000720 <srand@plt>:
 720:	ff 25 92 18 20 00    	jmpq   *0x201892(%rip)        # 201fb8 <srand@GLIBC_2.2.5>
 726:	68 04 00 00 00       	pushq  $0x4
 72b:	e9 a0 ff ff ff       	jmpq   6d0 <.plt>

0000000000000730 <time@plt>:
 730:	ff 25 8a 18 20 00    	jmpq   *0x20188a(%rip)        # 201fc0 <time@GLIBC_2.2.5>
 736:	68 05 00 00 00       	pushq  $0x5
 73b:	e9 90 ff ff ff       	jmpq   6d0 <.plt>

0000000000000740 <__isoc99_scanf@plt>:
 740:	ff 25 82 18 20 00    	jmpq   *0x201882(%rip)        # 201fc8 <__isoc99_scanf@GLIBC_2.7>
 746:	68 06 00 00 00       	pushq  $0x6
 74b:	e9 80 ff ff ff       	jmpq   6d0 <.plt>

0000000000000750 <rand@plt>:
 750:	ff 25 7a 18 20 00    	jmpq   *0x20187a(%rip)        # 201fd0 <rand@GLIBC_2.2.5>
 756:	68 07 00 00 00       	pushq  $0x7
 75b:	e9 70 ff ff ff       	jmpq   6d0 <.plt>

Disassembly of section .plt.got:

0000000000000760 <__cxa_finalize@plt>:
 760:	ff 25 92 18 20 00    	jmpq   *0x201892(%rip)        # 201ff8 <__cxa_finalize@GLIBC_2.2.5>
 766:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000000770 <_start>:
 770:	31 ed                	xor    %ebp,%ebp
 772:	49 89 d1             	mov    %rdx,%r9
 775:	5e                   	pop    %rsi
 776:	48 89 e2             	mov    %rsp,%rdx
 779:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
 77d:	50                   	push   %rax
 77e:	54                   	push   %rsp
 77f:	4c 8d 05 ea 04 00 00 	lea    0x4ea(%rip),%r8        # c70 <__libc_csu_fini>
 786:	48 8d 0d 73 04 00 00 	lea    0x473(%rip),%rcx        # c00 <__libc_csu_init>
 78d:	48 8d 3d e6 00 00 00 	lea    0xe6(%rip),%rdi        # 87a <main>
 794:	ff 15 46 18 20 00    	callq  *0x201846(%rip)        # 201fe0 <__libc_start_main@GLIBC_2.2.5>
 79a:	f4                   	hlt    
 79b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000007a0 <deregister_tm_clones>:
 7a0:	48 8d 3d 69 18 20 00 	lea    0x201869(%rip),%rdi        # 202010 <__TMC_END__>
 7a7:	55                   	push   %rbp
 7a8:	48 8d 05 61 18 20 00 	lea    0x201861(%rip),%rax        # 202010 <__TMC_END__>
 7af:	48 39 f8             	cmp    %rdi,%rax
 7b2:	48 89 e5             	mov    %rsp,%rbp
 7b5:	74 19                	je     7d0 <deregister_tm_clones+0x30>
 7b7:	48 8b 05 1a 18 20 00 	mov    0x20181a(%rip),%rax        # 201fd8 <_ITM_deregisterTMCloneTable>
 7be:	48 85 c0             	test   %rax,%rax
 7c1:	74 0d                	je     7d0 <deregister_tm_clones+0x30>
 7c3:	5d                   	pop    %rbp
 7c4:	ff e0                	jmpq   *%rax
 7c6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 7cd:	00 00 00 
 7d0:	5d                   	pop    %rbp
 7d1:	c3                   	retq   
 7d2:	0f 1f 40 00          	nopl   0x0(%rax)
 7d6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 7dd:	00 00 00 

00000000000007e0 <register_tm_clones>:
 7e0:	48 8d 3d 29 18 20 00 	lea    0x201829(%rip),%rdi        # 202010 <__TMC_END__>
 7e7:	48 8d 35 22 18 20 00 	lea    0x201822(%rip),%rsi        # 202010 <__TMC_END__>
 7ee:	55                   	push   %rbp
 7ef:	48 29 fe             	sub    %rdi,%rsi
 7f2:	48 89 e5             	mov    %rsp,%rbp
 7f5:	48 c1 fe 03          	sar    $0x3,%rsi
 7f9:	48 89 f0             	mov    %rsi,%rax
 7fc:	48 c1 e8 3f          	shr    $0x3f,%rax
 800:	48 01 c6             	add    %rax,%rsi
 803:	48 d1 fe             	sar    %rsi
 806:	74 18                	je     820 <register_tm_clones+0x40>
 808:	48 8b 05 e1 17 20 00 	mov    0x2017e1(%rip),%rax        # 201ff0 <_ITM_registerTMCloneTable>
 80f:	48 85 c0             	test   %rax,%rax
 812:	74 0c                	je     820 <register_tm_clones+0x40>
 814:	5d                   	pop    %rbp
 815:	ff e0                	jmpq   *%rax
 817:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 81e:	00 00 
 820:	5d                   	pop    %rbp
 821:	c3                   	retq   
 822:	0f 1f 40 00          	nopl   0x0(%rax)
 826:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 82d:	00 00 00 

0000000000000830 <__do_global_dtors_aux>:
 830:	80 3d d9 17 20 00 00 	cmpb   $0x0,0x2017d9(%rip)        # 202010 <__TMC_END__>
 837:	75 2f                	jne    868 <__do_global_dtors_aux+0x38>
 839:	48 83 3d b7 17 20 00 	cmpq   $0x0,0x2017b7(%rip)        # 201ff8 <__cxa_finalize@GLIBC_2.2.5>
 840:	00 
 841:	55                   	push   %rbp
 842:	48 89 e5             	mov    %rsp,%rbp
 845:	74 0c                	je     853 <__do_global_dtors_aux+0x23>
 847:	48 8b 3d ba 17 20 00 	mov    0x2017ba(%rip),%rdi        # 202008 <__dso_handle>
 84e:	e8 0d ff ff ff       	callq  760 <__cxa_finalize@plt>
 853:	e8 48 ff ff ff       	callq  7a0 <deregister_tm_clones>
 858:	c6 05 b1 17 20 00 01 	movb   $0x1,0x2017b1(%rip)        # 202010 <__TMC_END__>
 85f:	5d                   	pop    %rbp
 860:	c3                   	retq   
 861:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 868:	f3 c3                	repz retq 
 86a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000000870 <frame_dummy>:
 870:	55                   	push   %rbp
 871:	48 89 e5             	mov    %rsp,%rbp
 874:	5d                   	pop    %rbp
 875:	e9 66 ff ff ff       	jmpq   7e0 <register_tm_clones>

000000000000087a <main>:
 87a:	55                   	push   %rbp
 87b:	48 89 e5             	mov    %rsp,%rbp
 87e:	48 83 c4 80          	add    $0xffffffffffffff80,%rsp
 882:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
 889:	00 00 
 88b:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
 88f:	31 c0                	xor    %eax,%eax
 891:	c7 45 98 00 00 00 00 	movl   $0x0,-0x68(%rbp)
 898:	bf 00 00 00 00       	mov    $0x0,%edi
 89d:	e8 8e fe ff ff       	callq  730 <time@plt>
 8a2:	48 89 c7             	mov    %rax,%rdi
 8a5:	b8 00 00 00 00       	mov    $0x0,%eax
 8aa:	e8 71 fe ff ff       	callq  720 <srand@plt>
 8af:	c7 45 94 00 00 00 00 	movl   $0x0,-0x6c(%rbp)
 8b6:	eb 54                	jmp    90c <main+0x92>
 8b8:	b8 00 00 00 00       	mov    $0x0,%eax
 8bd:	e8 8e fe ff ff       	callq  750 <rand@plt>
 8c2:	89 c1                	mov    %eax,%ecx
 8c4:	ba 67 66 66 66       	mov    $0x66666667,%edx
 8c9:	89 c8                	mov    %ecx,%eax
 8cb:	f7 ea                	imul   %edx
 8cd:	c1 fa 02             	sar    $0x2,%edx
 8d0:	89 c8                	mov    %ecx,%eax
 8d2:	c1 f8 1f             	sar    $0x1f,%eax
 8d5:	29 c2                	sub    %eax,%edx
 8d7:	89 d0                	mov    %edx,%eax
 8d9:	c1 e0 02             	shl    $0x2,%eax
 8dc:	01 d0                	add    %edx,%eax
 8de:	01 c0                	add    %eax,%eax
 8e0:	29 c1                	sub    %eax,%ecx
 8e2:	89 ca                	mov    %ecx,%edx
 8e4:	8d 42 01             	lea    0x1(%rdx),%eax
 8e7:	89 45 98             	mov    %eax,-0x68(%rbp)
 8ea:	8b 45 94             	mov    -0x6c(%rbp),%eax
 8ed:	48 98                	cltq   
 8ef:	8b 55 98             	mov    -0x68(%rbp),%edx
 8f2:	89 54 85 a0          	mov    %edx,-0x60(%rbp,%rax,4)
 8f6:	8b 45 94             	mov    -0x6c(%rbp),%eax
 8f9:	48 98                	cltq   
 8fb:	8b 54 85 a0          	mov    -0x60(%rbp,%rax,4),%edx
 8ff:	8b 45 94             	mov    -0x6c(%rbp),%eax
 902:	48 98                	cltq   
 904:	89 54 85 d0          	mov    %edx,-0x30(%rbp,%rax,4)
 908:	83 45 94 01          	addl   $0x1,-0x6c(%rbp)
 90c:	83 7d 94 09          	cmpl   $0x9,-0x6c(%rbp)
 910:	7e a6                	jle    8b8 <main+0x3e>
 912:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
 916:	48 8d 15 6b 03 00 00 	lea    0x36b(%rip),%rdx        # c88 <_IO_stdin_used+0x8>
 91d:	be 0a 00 00 00       	mov    $0xa,%esi
 922:	48 89 c7             	mov    %rax,%rdi
 925:	e8 2e 01 00 00       	callq  a58 <printResult>
 92a:	c6 45 8f 01          	movb   $0x1,-0x71(%rbp)
 92e:	e9 00 01 00 00       	jmpq   a33 <main+0x1b9>
 933:	48 8d 3d 5e 03 00 00 	lea    0x35e(%rip),%rdi        # c98 <_IO_stdin_used+0x18>
 93a:	b8 00 00 00 00       	mov    $0x0,%eax
 93f:	e8 cc fd ff ff       	callq  710 <printf@plt>
 944:	48 8d 3d 78 03 00 00 	lea    0x378(%rip),%rdi        # cc3 <_IO_stdin_used+0x43>
 94b:	b8 00 00 00 00       	mov    $0x0,%eax
 950:	e8 bb fd ff ff       	callq  710 <printf@plt>
 955:	c7 45 90 00 00 00 00 	movl   $0x0,-0x70(%rbp)
 95c:	48 8d 45 90          	lea    -0x70(%rbp),%rax
 960:	48 89 c6             	mov    %rax,%rsi
 963:	48 8d 3d 6b 03 00 00 	lea    0x36b(%rip),%rdi        # cd5 <_IO_stdin_used+0x55>
 96a:	b8 00 00 00 00       	mov    $0x0,%eax
 96f:	e8 cc fd ff ff       	callq  740 <__isoc99_scanf@plt>
 974:	c7 45 9c 00 00 00 00 	movl   $0x0,-0x64(%rbp)
 97b:	8b 45 90             	mov    -0x70(%rbp),%eax
 97e:	83 f8 02             	cmp    $0x2,%eax
 981:	74 2e                	je     9b1 <main+0x137>
 983:	83 f8 02             	cmp    $0x2,%eax
 986:	7f 0a                	jg     992 <main+0x118>
 988:	83 f8 01             	cmp    $0x1,%eax
 98b:	74 11                	je     99e <main+0x124>
 98d:	e9 83 00 00 00       	jmpq   a15 <main+0x19b>
 992:	83 f8 03             	cmp    $0x3,%eax
 995:	74 46                	je     9dd <main+0x163>
 997:	83 f8 04             	cmp    $0x4,%eax
 99a:	74 73                	je     a0f <main+0x195>
 99c:	eb 77                	jmp    a15 <main+0x19b>
 99e:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
 9a2:	be 0a 00 00 00       	mov    $0xa,%esi
 9a7:	48 89 c7             	mov    %rax,%rdi
 9aa:	e8 1f 01 00 00       	callq  ace <BubbleSort>
 9af:	eb 76                	jmp    a27 <main+0x1ad>
 9b1:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
 9b5:	be 0a 00 00 00       	mov    $0xa,%esi
 9ba:	48 89 c7             	mov    %rax,%rdi
 9bd:	e8 f2 01 00 00       	callq  bb4 <add>
 9c2:	89 45 9c             	mov    %eax,-0x64(%rbp)
 9c5:	8b 45 9c             	mov    -0x64(%rbp),%eax
 9c8:	89 c6                	mov    %eax,%esi
 9ca:	48 8d 3d 07 03 00 00 	lea    0x307(%rip),%rdi        # cd8 <_IO_stdin_used+0x58>
 9d1:	b8 00 00 00 00       	mov    $0x0,%eax
 9d6:	e8 35 fd ff ff       	callq  710 <printf@plt>
 9db:	eb 4a                	jmp    a27 <main+0x1ad>
 9dd:	48 8d 45 d0          	lea    -0x30(%rbp),%rax
 9e1:	48 8d 15 04 03 00 00 	lea    0x304(%rip),%rdx        # cec <_IO_stdin_used+0x6c>
 9e8:	be 0a 00 00 00       	mov    $0xa,%esi
 9ed:	48 89 c7             	mov    %rax,%rdi
 9f0:	e8 63 00 00 00       	callq  a58 <printResult>
 9f5:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
 9f9:	48 8d 15 fe 02 00 00 	lea    0x2fe(%rip),%rdx        # cfe <_IO_stdin_used+0x7e>
 a00:	be 0a 00 00 00       	mov    $0xa,%esi
 a05:	48 89 c7             	mov    %rax,%rdi
 a08:	e8 4b 00 00 00       	callq  a58 <printResult>
 a0d:	eb 18                	jmp    a27 <main+0x1ad>
 a0f:	c6 45 8f 00          	movb   $0x0,-0x71(%rbp)
 a13:	eb 12                	jmp    a27 <main+0x1ad>
 a15:	48 8d 3d f4 02 00 00 	lea    0x2f4(%rip),%rdi        # d10 <_IO_stdin_used+0x90>
 a1c:	b8 00 00 00 00       	mov    $0x0,%eax
 a21:	e8 ea fc ff ff       	callq  710 <printf@plt>
 a26:	90                   	nop
 a27:	48 8d 3d 10 03 00 00 	lea    0x310(%rip),%rdi        # d3e <_IO_stdin_used+0xbe>
 a2e:	e8 bd fc ff ff       	callq  6f0 <puts@plt>
 a33:	80 7d 8f 00          	cmpb   $0x0,-0x71(%rbp)
 a37:	0f 85 f6 fe ff ff    	jne    933 <main+0xb9>
 a3d:	b8 00 00 00 00       	mov    $0x0,%eax
 a42:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
 a46:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
 a4d:	00 00 
 a4f:	74 05                	je     a56 <main+0x1dc>
 a51:	e8 aa fc ff ff       	callq  700 <__stack_chk_fail@plt>
 a56:	c9                   	leaveq 
 a57:	c3                   	retq   

0000000000000a58 <printResult>:
 a58:	55                   	push   %rbp
 a59:	48 89 e5             	mov    %rsp,%rbp
 a5c:	48 83 ec 30          	sub    $0x30,%rsp
 a60:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
 a64:	89 75 e4             	mov    %esi,-0x1c(%rbp)
 a67:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
 a6b:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 a6f:	48 89 c6             	mov    %rax,%rsi
 a72:	48 8d 3d cd 02 00 00 	lea    0x2cd(%rip),%rdi        # d46 <_IO_stdin_used+0xc6>
 a79:	b8 00 00 00 00       	mov    $0x0,%eax
 a7e:	e8 8d fc ff ff       	callq  710 <printf@plt>
 a83:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
 a8a:	eb 2d                	jmp    ab9 <printResult+0x61>
 a8c:	8b 45 fc             	mov    -0x4(%rbp),%eax
 a8f:	48 98                	cltq   
 a91:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 a98:	00 
 a99:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 a9d:	48 01 d0             	add    %rdx,%rax
 aa0:	8b 00                	mov    (%rax),%eax
 aa2:	89 c6                	mov    %eax,%esi
 aa4:	48 8d 3d 9e 02 00 00 	lea    0x29e(%rip),%rdi        # d49 <_IO_stdin_used+0xc9>
 aab:	b8 00 00 00 00       	mov    $0x0,%eax
 ab0:	e8 5b fc ff ff       	callq  710 <printf@plt>
 ab5:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
 ab9:	8b 45 fc             	mov    -0x4(%rbp),%eax
 abc:	3b 45 e4             	cmp    -0x1c(%rbp),%eax
 abf:	7c cb                	jl     a8c <printResult+0x34>
 ac1:	bf 0a 00 00 00       	mov    $0xa,%edi
 ac6:	e8 15 fc ff ff       	callq  6e0 <putchar@plt>
 acb:	90                   	nop
 acc:	c9                   	leaveq 
 acd:	c3                   	retq   

0000000000000ace <BubbleSort>:
 ace:	55                   	push   %rbp
 acf:	48 89 e5             	mov    %rsp,%rbp
 ad2:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
 ad6:	89 75 e4             	mov    %esi,-0x1c(%rbp)
 ad9:	83 7d e4 01          	cmpl   $0x1,-0x1c(%rbp)
 add:	0f 8e ce 00 00 00    	jle    bb1 <BubbleSort+0xe3>
 ae3:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
 aea:	e9 b1 00 00 00       	jmpq   ba0 <BubbleSort+0xd2>
 aef:	8b 45 e4             	mov    -0x1c(%rbp),%eax
 af2:	83 e8 01             	sub    $0x1,%eax
 af5:	89 45 f8             	mov    %eax,-0x8(%rbp)
 af8:	e9 93 00 00 00       	jmpq   b90 <BubbleSort+0xc2>
 afd:	8b 45 f8             	mov    -0x8(%rbp),%eax
 b00:	48 98                	cltq   
 b02:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 b09:	00 
 b0a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 b0e:	48 01 d0             	add    %rdx,%rax
 b11:	8b 10                	mov    (%rax),%edx
 b13:	8b 45 f8             	mov    -0x8(%rbp),%eax
 b16:	48 98                	cltq   
 b18:	48 c1 e0 02          	shl    $0x2,%rax
 b1c:	48 8d 48 fc          	lea    -0x4(%rax),%rcx
 b20:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 b24:	48 01 c8             	add    %rcx,%rax
 b27:	8b 00                	mov    (%rax),%eax
 b29:	39 c2                	cmp    %eax,%edx
 b2b:	7d 5f                	jge    b8c <BubbleSort+0xbe>
 b2d:	8b 45 f8             	mov    -0x8(%rbp),%eax
 b30:	48 98                	cltq   
 b32:	48 c1 e0 02          	shl    $0x2,%rax
 b36:	48 8d 50 fc          	lea    -0x4(%rax),%rdx
 b3a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 b3e:	48 01 d0             	add    %rdx,%rax
 b41:	8b 00                	mov    (%rax),%eax
 b43:	89 45 fc             	mov    %eax,-0x4(%rbp)
 b46:	8b 45 f8             	mov    -0x8(%rbp),%eax
 b49:	48 98                	cltq   
 b4b:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 b52:	00 
 b53:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 b57:	48 01 d0             	add    %rdx,%rax
 b5a:	8b 55 f8             	mov    -0x8(%rbp),%edx
 b5d:	48 63 d2             	movslq %edx,%rdx
 b60:	48 c1 e2 02          	shl    $0x2,%rdx
 b64:	48 8d 4a fc          	lea    -0x4(%rdx),%rcx
 b68:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
 b6c:	48 01 ca             	add    %rcx,%rdx
 b6f:	8b 00                	mov    (%rax),%eax
 b71:	89 02                	mov    %eax,(%rdx)
 b73:	8b 45 f8             	mov    -0x8(%rbp),%eax
 b76:	48 98                	cltq   
 b78:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 b7f:	00 
 b80:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 b84:	48 01 c2             	add    %rax,%rdx
 b87:	8b 45 fc             	mov    -0x4(%rbp),%eax
 b8a:	89 02                	mov    %eax,(%rdx)
 b8c:	83 6d f8 01          	subl   $0x1,-0x8(%rbp)
 b90:	8b 45 f8             	mov    -0x8(%rbp),%eax
 b93:	3b 45 f4             	cmp    -0xc(%rbp),%eax
 b96:	0f 8f 61 ff ff ff    	jg     afd <BubbleSort+0x2f>
 b9c:	83 45 f4 01          	addl   $0x1,-0xc(%rbp)
 ba0:	8b 45 e4             	mov    -0x1c(%rbp),%eax
 ba3:	83 e8 01             	sub    $0x1,%eax
 ba6:	39 45 f4             	cmp    %eax,-0xc(%rbp)
 ba9:	0f 8c 40 ff ff ff    	jl     aef <BubbleSort+0x21>
 baf:	eb 01                	jmp    bb2 <BubbleSort+0xe4>
 bb1:	90                   	nop
 bb2:	5d                   	pop    %rbp
 bb3:	c3                   	retq   

0000000000000bb4 <add>:
 bb4:	55                   	push   %rbp
 bb5:	48 89 e5             	mov    %rsp,%rbp
 bb8:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
 bbc:	89 75 e4             	mov    %esi,-0x1c(%rbp)
 bbf:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
 bc6:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
 bcd:	eb 1d                	jmp    bec <add+0x38>
 bcf:	8b 45 fc             	mov    -0x4(%rbp),%eax
 bd2:	48 98                	cltq   
 bd4:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
 bdb:	00 
 bdc:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 be0:	48 01 d0             	add    %rdx,%rax
 be3:	8b 00                	mov    (%rax),%eax
 be5:	01 45 f8             	add    %eax,-0x8(%rbp)
 be8:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
 bec:	8b 45 fc             	mov    -0x4(%rbp),%eax
 bef:	3b 45 e4             	cmp    -0x1c(%rbp),%eax
 bf2:	7c db                	jl     bcf <add+0x1b>
 bf4:	8b 45 f8             	mov    -0x8(%rbp),%eax
 bf7:	5d                   	pop    %rbp
 bf8:	c3                   	retq   
 bf9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000000c00 <__libc_csu_init>:
 c00:	41 57                	push   %r15
 c02:	41 56                	push   %r14
 c04:	49 89 d7             	mov    %rdx,%r15
 c07:	41 55                	push   %r13
 c09:	41 54                	push   %r12
 c0b:	4c 8d 25 6e 11 20 00 	lea    0x20116e(%rip),%r12        # 201d80 <__frame_dummy_init_array_entry>
 c12:	55                   	push   %rbp
 c13:	48 8d 2d 6e 11 20 00 	lea    0x20116e(%rip),%rbp        # 201d88 <__init_array_end>
 c1a:	53                   	push   %rbx
 c1b:	41 89 fd             	mov    %edi,%r13d
 c1e:	49 89 f6             	mov    %rsi,%r14
 c21:	4c 29 e5             	sub    %r12,%rbp
 c24:	48 83 ec 08          	sub    $0x8,%rsp
 c28:	48 c1 fd 03          	sar    $0x3,%rbp
 c2c:	e8 87 fa ff ff       	callq  6b8 <_init>
 c31:	48 85 ed             	test   %rbp,%rbp
 c34:	74 20                	je     c56 <__libc_csu_init+0x56>
 c36:	31 db                	xor    %ebx,%ebx
 c38:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 c3f:	00 
 c40:	4c 89 fa             	mov    %r15,%rdx
 c43:	4c 89 f6             	mov    %r14,%rsi
 c46:	44 89 ef             	mov    %r13d,%edi
 c49:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
 c4d:	48 83 c3 01          	add    $0x1,%rbx
 c51:	48 39 dd             	cmp    %rbx,%rbp
 c54:	75 ea                	jne    c40 <__libc_csu_init+0x40>
 c56:	48 83 c4 08          	add    $0x8,%rsp
 c5a:	5b                   	pop    %rbx
 c5b:	5d                   	pop    %rbp
 c5c:	41 5c                	pop    %r12
 c5e:	41 5d                	pop    %r13
 c60:	41 5e                	pop    %r14
 c62:	41 5f                	pop    %r15
 c64:	c3                   	retq   
 c65:	90                   	nop
 c66:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 c6d:	00 00 00 

0000000000000c70 <__libc_csu_fini>:
 c70:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000000c74 <_fini>:
 c74:	48 83 ec 08          	sub    $0x8,%rsp
 c78:	48 83 c4 08          	add    $0x8,%rsp
 c7c:	c3                   	retq   

Disassembly of section .rodata:

0000000000000c80 <_IO_stdin_used>:
 c80:	01 00                	add    %eax,(%rax)
 c82:	02 00                	add    (%rax),%al
 c84:	00 00                	add    %al,(%rax)
 c86:	00 00                	add    %al,(%rax)
 c88:	0a 72 61             	or     0x61(%rdx),%dh
 c8b:	6e                   	outsb  %ds:(%rsi),(%dx)
 c8c:	64 6f                	outsl  %fs:(%rsi),(%dx)
 c8e:	6d                   	insl   (%dx),%es:(%rdi)
 c8f:	20 61 72             	and    %ah,0x72(%rcx)
 c92:	72 61                	jb     cf5 <_IO_stdin_used+0x75>
 c94:	79 3a                	jns    cd0 <_IO_stdin_used+0x50>
 c96:	20 00                	and    %al,(%rax)
 c98:	0a 31                	or     (%rcx),%dh
 c9a:	2e 42 75 62          	rex.X jne,pn d00 <_IO_stdin_used+0x80>
 c9e:	62                   	(bad)  
 c9f:	6c                   	insb   (%dx),%es:(%rdi)
 ca0:	65 20 53 6f          	and    %dl,%gs:0x6f(%rbx)
 ca4:	72 74                	jb     d1a <_IO_stdin_used+0x9a>
 ca6:	0a 32                	or     (%rdx),%dh
 ca8:	2e 73 75             	jae,pn d20 <_IO_stdin_used+0xa0>
 cab:	6d                   	insl   (%dx),%es:(%rdi)
 cac:	0a 33                	or     (%rbx),%dh
 cae:	2e 70 72             	jo,pn  d23 <_IO_stdin_used+0xa3>
 cb1:	69 6e 74 20 72 65 73 	imul   $0x73657220,0x74(%rsi),%ebp
 cb8:	75 6c                	jne    d26 <_IO_stdin_used+0xa6>
 cba:	74 0a                	je     cc6 <_IO_stdin_used+0x46>
 cbc:	34 2e                	xor    $0x2e,%al
 cbe:	65 78 69             	gs js  d2a <_IO_stdin_used+0xaa>
 cc1:	74 00                	je     cc3 <_IO_stdin_used+0x43>
 cc3:	0a 63 68             	or     0x68(%rbx),%ah
 cc6:	6f                   	outsl  %ds:(%rsi),(%dx)
 cc7:	6f                   	outsl  %ds:(%rsi),(%dx)
 cc8:	73 65                	jae    d2f <_IO_stdin_used+0xaf>
 cca:	20 61 20             	and    %ah,0x20(%rcx)
 ccd:	6e                   	outsb  %ds:(%rsi),(%dx)
 cce:	75 6d                	jne    d3d <_IO_stdin_used+0xbd>
 cd0:	62                   	(bad)  
 cd1:	65 72 3a             	gs jb  d0e <_IO_stdin_used+0x8e>
 cd4:	00 25 64 00 0a 72    	add    %ah,0x720a0064(%rip)        # 720a0d3e <_end+0x71e9ed26>
 cda:	65 73 75             	gs jae d52 <__GNU_EH_FRAME_HDR+0x2>
 cdd:	6c                   	insb   (%dx),%es:(%rdi)
 cde:	74 20                	je     d00 <_IO_stdin_used+0x80>
 ce0:	6f                   	outsl  %ds:(%rsi),(%dx)
 ce1:	66 20 73 75          	data16 and %dh,0x75(%rbx)
 ce5:	6d                   	insl   (%dx),%es:(%rdi)
 ce6:	3a 20                	cmp    (%rax),%ah
 ce8:	25 64 0a 00 0a       	and    $0xa000a64,%eax
 ced:	6f                   	outsl  %ds:(%rsi),(%dx)
 cee:	72 69                	jb     d59 <__GNU_EH_FRAME_HDR+0x9>
 cf0:	67 69 6e 61 6c 20 61 	imul   $0x7261206c,0x61(%esi),%ebp
 cf7:	72 
 cf8:	72 61                	jb     d5b <__GNU_EH_FRAME_HDR+0xb>
 cfa:	79 3a                	jns    d36 <_IO_stdin_used+0xb6>
 cfc:	09 00                	or     %eax,(%rax)
 cfe:	0a 73 6f             	or     0x6f(%rbx),%dh
 d01:	72 74                	jb     d77 <__GNU_EH_FRAME_HDR+0x27>
 d03:	65 64 20 61 72       	gs and %ah,%fs:0x72(%rcx)
 d08:	72 61                	jb     d6b <__GNU_EH_FRAME_HDR+0x1b>
 d0a:	79 3a                	jns    d46 <_IO_stdin_used+0xc6>
 d0c:	09 00                	or     %eax,(%rax)
 d0e:	00 00                	add    %al,(%rax)
 d10:	0a 70 6c             	or     0x6c(%rax),%dh
 d13:	65 61                	gs (bad) 
 d15:	73 65                	jae    d7c <__GNU_EH_FRAME_HDR+0x2c>
 d17:	20 63 68             	and    %ah,0x68(%rbx)
 d1a:	6f                   	outsl  %ds:(%rsi),(%dx)
 d1b:	6f                   	outsl  %ds:(%rsi),(%dx)
 d1c:	73 65                	jae    d83 <__GNU_EH_FRAME_HDR+0x33>
 d1e:	20 61 20             	and    %ah,0x20(%rcx)
 d21:	63 6f 72             	movslq 0x72(%rdi),%ebp
 d24:	72 65                	jb     d8b <__GNU_EH_FRAME_HDR+0x3b>
 d26:	63 74 20 6e          	movslq 0x6e(%rax,%riz,1),%esi
 d2a:	75 6d                	jne    d99 <__GNU_EH_FRAME_HDR+0x49>
 d2c:	62                   	(bad)  
 d2d:	65 72 20             	gs jb  d50 <__GNU_EH_FRAME_HDR>
 d30:	61                   	(bad)  
 d31:	6e                   	outsb  %ds:(%rsi),(%dx)
 d32:	64 20 63 6f          	and    %ah,%fs:0x6f(%rbx)
 d36:	6e                   	outsb  %ds:(%rsi),(%dx)
 d37:	74 69                	je     da2 <__GNU_EH_FRAME_HDR+0x52>
 d39:	6e                   	outsb  %ds:(%rsi),(%dx)
 d3a:	75 65                	jne    da1 <__GNU_EH_FRAME_HDR+0x51>
 d3c:	21 00                	and    %eax,(%rax)
 d3e:	0a 44 6f 6e          	or     0x6e(%rdi,%rbp,2),%al
 d42:	65 21 0a             	and    %ecx,%gs:(%rdx)
 d45:	00 25 73 00 25 35    	add    %ah,0x35250073(%rip)        # 35250dbe <_end+0x3504eda6>
 d4b:	64                   	fs
	...

Disassembly of section .eh_frame_hdr:

0000000000000d50 <__GNU_EH_FRAME_HDR>:
 d50:	01 1b                	add    %ebx,(%rbx)
 d52:	03 3b                	add    (%rbx),%edi
 d54:	54                   	push   %rsp
 d55:	00 00                	add    %al,(%rax)
 d57:	00 09                	add    %cl,(%rcx)
 d59:	00 00                	add    %al,(%rax)
 d5b:	00 80 f9 ff ff a0    	add    %al,-0x5f000007(%rax)
 d61:	00 00                	add    %al,(%rax)
 d63:	00 10                	add    %dl,(%rax)
 d65:	fa                   	cli    
 d66:	ff                   	(bad)  
 d67:	ff c8                	dec    %eax
 d69:	00 00                	add    %al,(%rax)
 d6b:	00 20                	add    %ah,(%rax)
 d6d:	fa                   	cli    
 d6e:	ff                   	(bad)  
 d6f:	ff 70 00             	pushq  0x0(%rax)
 d72:	00 00                	add    %al,(%rax)
 d74:	2a fb                	sub    %bl,%bh
 d76:	ff                   	(bad)  
 d77:	ff e0                	jmpq   *%rax
 d79:	00 00                	add    %al,(%rax)
 d7b:	00 08                	add    %cl,(%rax)
 d7d:	fd                   	std    
 d7e:	ff                   	(bad)  
 d7f:	ff 00                	incl   (%rax)
 d81:	01 00                	add    %eax,(%rax)
 d83:	00 7e fd             	add    %bh,-0x3(%rsi)
 d86:	ff                   	(bad)  
 d87:	ff 20                	jmpq   *(%rax)
 d89:	01 00                	add    %eax,(%rax)
 d8b:	00 64 fe ff          	add    %ah,-0x1(%rsi,%rdi,8)
 d8f:	ff 40 01             	incl   0x1(%rax)
 d92:	00 00                	add    %al,(%rax)
 d94:	b0 fe                	mov    $0xfe,%al
 d96:	ff                   	(bad)  
 d97:	ff 60 01             	jmpq   *0x1(%rax)
 d9a:	00 00                	add    %al,(%rax)
 d9c:	20 ff                	and    %bh,%bh
 d9e:	ff                   	(bad)  
 d9f:	ff                   	.byte 0xff
 da0:	a8 01                	test   $0x1,%al
	...

Disassembly of section .eh_frame:

0000000000000da8 <__FRAME_END__-0x164>:
 da8:	14 00                	adc    $0x0,%al
 daa:	00 00                	add    %al,(%rax)
 dac:	00 00                	add    %al,(%rax)
 dae:	00 00                	add    %al,(%rax)
 db0:	01 7a 52             	add    %edi,0x52(%rdx)
 db3:	00 01                	add    %al,(%rcx)
 db5:	78 10                	js     dc7 <__GNU_EH_FRAME_HDR+0x77>
 db7:	01 1b                	add    %ebx,(%rbx)
 db9:	0c 07                	or     $0x7,%al
 dbb:	08 90 01 07 10 14    	or     %dl,0x14100701(%rax)
 dc1:	00 00                	add    %al,(%rax)
 dc3:	00 1c 00             	add    %bl,(%rax,%rax,1)
 dc6:	00 00                	add    %al,(%rax)
 dc8:	a8 f9                	test   $0xf9,%al
 dca:	ff                   	(bad)  
 dcb:	ff 2b                	ljmp   *(%rbx)
	...
 dd5:	00 00                	add    %al,(%rax)
 dd7:	00 14 00             	add    %dl,(%rax,%rax,1)
 dda:	00 00                	add    %al,(%rax)
 ddc:	00 00                	add    %al,(%rax)
 dde:	00 00                	add    %al,(%rax)
 de0:	01 7a 52             	add    %edi,0x52(%rdx)
 de3:	00 01                	add    %al,(%rcx)
 de5:	78 10                	js     df7 <__GNU_EH_FRAME_HDR+0xa7>
 de7:	01 1b                	add    %ebx,(%rbx)
 de9:	0c 07                	or     $0x7,%al
 deb:	08 90 01 00 00 24    	or     %dl,0x24000001(%rax)
 df1:	00 00                	add    %al,(%rax)
 df3:	00 1c 00             	add    %bl,(%rax,%rax,1)
 df6:	00 00                	add    %al,(%rax)
 df8:	d8 f8                	fdivr  %st(0),%st
 dfa:	ff                   	(bad)  
 dfb:	ff 90 00 00 00 00    	callq  *0x0(%rax)
 e01:	0e                   	(bad)  
 e02:	10 46 0e             	adc    %al,0xe(%rsi)
 e05:	18 4a 0f             	sbb    %cl,0xf(%rdx)
 e08:	0b 77 08             	or     0x8(%rdi),%esi
 e0b:	80 00 3f             	addb   $0x3f,(%rax)
 e0e:	1a 3b                	sbb    (%rbx),%bh
 e10:	2a 33                	sub    (%rbx),%dh
 e12:	24 22                	and    $0x22,%al
 e14:	00 00                	add    %al,(%rax)
 e16:	00 00                	add    %al,(%rax)
 e18:	14 00                	adc    $0x0,%al
 e1a:	00 00                	add    %al,(%rax)
 e1c:	44 00 00             	add    %r8b,(%rax)
 e1f:	00 40 f9             	add    %al,-0x7(%rax)
 e22:	ff                   	(bad)  
 e23:	ff 08                	decl   (%rax)
	...
 e2d:	00 00                	add    %al,(%rax)
 e2f:	00 1c 00             	add    %bl,(%rax,%rax,1)
 e32:	00 00                	add    %al,(%rax)
 e34:	5c                   	pop    %rsp
 e35:	00 00                	add    %al,(%rax)
 e37:	00 42 fa             	add    %al,-0x6(%rdx)
 e3a:	ff                   	(bad)  
 e3b:	ff                   	(bad)  
 e3c:	de 01                	fiadds (%rcx)
 e3e:	00 00                	add    %al,(%rax)
 e40:	00 41 0e             	add    %al,0xe(%rcx)
 e43:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
 e49:	03 d9                	add    %ecx,%ebx
 e4b:	01 0c 07             	add    %ecx,(%rdi,%rax,1)
 e4e:	08 00                	or     %al,(%rax)
 e50:	1c 00                	sbb    $0x0,%al
 e52:	00 00                	add    %al,(%rax)
 e54:	7c 00                	jl     e56 <__GNU_EH_FRAME_HDR+0x106>
 e56:	00 00                	add    %al,(%rax)
 e58:	00 fc                	add    %bh,%ah
 e5a:	ff                   	(bad)  
 e5b:	ff 76 00             	pushq  0x0(%rsi)
 e5e:	00 00                	add    %al,(%rax)
 e60:	00 41 0e             	add    %al,0xe(%rcx)
 e63:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
 e69:	02 71 0c             	add    0xc(%rcx),%dh
 e6c:	07                   	(bad)  
 e6d:	08 00                	or     %al,(%rax)
 e6f:	00 1c 00             	add    %bl,(%rax,%rax,1)
 e72:	00 00                	add    %al,(%rax)
 e74:	9c                   	pushfq 
 e75:	00 00                	add    %al,(%rax)
 e77:	00 56 fc             	add    %dl,-0x4(%rsi)
 e7a:	ff                   	(bad)  
 e7b:	ff e6                	jmpq   *%rsi
 e7d:	00 00                	add    %al,(%rax)
 e7f:	00 00                	add    %al,(%rax)
 e81:	41 0e                	rex.B (bad) 
 e83:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
 e89:	02 e1                	add    %cl,%ah
 e8b:	0c 07                	or     $0x7,%al
 e8d:	08 00                	or     %al,(%rax)
 e8f:	00 1c 00             	add    %bl,(%rax,%rax,1)
 e92:	00 00                	add    %al,(%rax)
 e94:	bc 00 00 00 1c       	mov    $0x1c000000,%esp
 e99:	fd                   	std    
 e9a:	ff                   	(bad)  
 e9b:	ff 45 00             	incl   0x0(%rbp)
 e9e:	00 00                	add    %al,(%rax)
 ea0:	00 41 0e             	add    %al,0xe(%rcx)
 ea3:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
 ea9:	02 40 0c             	add    0xc(%rax),%al
 eac:	07                   	(bad)  
 ead:	08 00                	or     %al,(%rax)
 eaf:	00 44 00 00          	add    %al,0x0(%rax,%rax,1)
 eb3:	00 dc                	add    %bl,%ah
 eb5:	00 00                	add    %al,(%rax)
 eb7:	00 48 fd             	add    %cl,-0x3(%rax)
 eba:	ff                   	(bad)  
 ebb:	ff 65 00             	jmpq   *0x0(%rbp)
 ebe:	00 00                	add    %al,(%rax)
 ec0:	00 42 0e             	add    %al,0xe(%rdx)
 ec3:	10 8f 02 42 0e 18    	adc    %cl,0x180e4202(%rdi)
 ec9:	8e 03                	mov    (%rbx),%es
 ecb:	45 0e                	rex.RB (bad) 
 ecd:	20 8d 04 42 0e 28    	and    %cl,0x280e4204(%rbp)
 ed3:	8c 05 48 0e 30 86    	mov    %es,-0x79cff1b8(%rip)        # ffffffff86301d21 <_end+0xffffffff860ffd09>
 ed9:	06                   	(bad)  
 eda:	48 0e                	rex.W (bad) 
 edc:	38 83 07 4d 0e 40    	cmp    %al,0x400e4d07(%rbx)
 ee2:	72 0e                	jb     ef2 <__GNU_EH_FRAME_HDR+0x1a2>
 ee4:	38 41 0e             	cmp    %al,0xe(%rcx)
 ee7:	30 41 0e             	xor    %al,0xe(%rcx)
 eea:	28 42 0e             	sub    %al,0xe(%rdx)
 eed:	20 42 0e             	and    %al,0xe(%rdx)
 ef0:	18 42 0e             	sbb    %al,0xe(%rdx)
 ef3:	10 42 0e             	adc    %al,0xe(%rdx)
 ef6:	08 00                	or     %al,(%rax)
 ef8:	10 00                	adc    %al,(%rax)
 efa:	00 00                	add    %al,(%rax)
 efc:	24 01                	and    $0x1,%al
 efe:	00 00                	add    %al,(%rax)
 f00:	70 fd                	jo     eff <__GNU_EH_FRAME_HDR+0x1af>
 f02:	ff                   	(bad)  
 f03:	ff 02                	incl   (%rdx)
 f05:	00 00                	add    %al,(%rax)
 f07:	00 00                	add    %al,(%rax)
 f09:	00 00                	add    %al,(%rax)
	...

0000000000000f0c <__FRAME_END__>:
 f0c:	00 00                	add    %al,(%rax)
	...

Disassembly of section .init_array:

0000000000201d80 <__frame_dummy_init_array_entry>:
  201d80:	70 08                	jo     201d8a <__init_array_end+0x2>
  201d82:	00 00                	add    %al,(%rax)
  201d84:	00 00                	add    %al,(%rax)
	...

Disassembly of section .fini_array:

0000000000201d88 <__do_global_dtors_aux_fini_array_entry>:
  201d88:	30 08                	xor    %cl,(%rax)
  201d8a:	00 00                	add    %al,(%rax)
  201d8c:	00 00                	add    %al,(%rax)
	...

Disassembly of section .dynamic:

0000000000201d90 <_DYNAMIC>:
  201d90:	01 00                	add    %eax,(%rax)
  201d92:	00 00                	add    %al,(%rax)
  201d94:	00 00                	add    %al,(%rax)
  201d96:	00 00                	add    %al,(%rax)
  201d98:	01 00                	add    %eax,(%rax)
  201d9a:	00 00                	add    %al,(%rax)
  201d9c:	00 00                	add    %al,(%rax)
  201d9e:	00 00                	add    %al,(%rax)
  201da0:	0c 00                	or     $0x0,%al
  201da2:	00 00                	add    %al,(%rax)
  201da4:	00 00                	add    %al,(%rax)
  201da6:	00 00                	add    %al,(%rax)
  201da8:	b8 06 00 00 00       	mov    $0x6,%eax
  201dad:	00 00                	add    %al,(%rax)
  201daf:	00 0d 00 00 00 00    	add    %cl,0x0(%rip)        # 201db5 <_DYNAMIC+0x25>
  201db5:	00 00                	add    %al,(%rax)
  201db7:	00 74 0c 00          	add    %dh,0x0(%rsp,%rcx,1)
  201dbb:	00 00                	add    %al,(%rax)
  201dbd:	00 00                	add    %al,(%rax)
  201dbf:	00 19                	add    %bl,(%rcx)
  201dc1:	00 00                	add    %al,(%rax)
  201dc3:	00 00                	add    %al,(%rax)
  201dc5:	00 00                	add    %al,(%rax)
  201dc7:	00 80 1d 20 00 00    	add    %al,0x201d(%rax)
  201dcd:	00 00                	add    %al,(%rax)
  201dcf:	00 1b                	add    %bl,(%rbx)
  201dd1:	00 00                	add    %al,(%rax)
  201dd3:	00 00                	add    %al,(%rax)
  201dd5:	00 00                	add    %al,(%rax)
  201dd7:	00 08                	add    %cl,(%rax)
  201dd9:	00 00                	add    %al,(%rax)
  201ddb:	00 00                	add    %al,(%rax)
  201ddd:	00 00                	add    %al,(%rax)
  201ddf:	00 1a                	add    %bl,(%rdx)
  201de1:	00 00                	add    %al,(%rax)
  201de3:	00 00                	add    %al,(%rax)
  201de5:	00 00                	add    %al,(%rax)
  201de7:	00 88 1d 20 00 00    	add    %cl,0x201d(%rax)
  201ded:	00 00                	add    %al,(%rax)
  201def:	00 1c 00             	add    %bl,(%rax,%rax,1)
  201df2:	00 00                	add    %al,(%rax)
  201df4:	00 00                	add    %al,(%rax)
  201df6:	00 00                	add    %al,(%rax)
  201df8:	08 00                	or     %al,(%rax)
  201dfa:	00 00                	add    %al,(%rax)
  201dfc:	00 00                	add    %al,(%rax)
  201dfe:	00 00                	add    %al,(%rax)
  201e00:	f5                   	cmc    
  201e01:	fe                   	(bad)  
  201e02:	ff 6f 00             	ljmp   *0x0(%rdi)
  201e05:	00 00                	add    %al,(%rax)
  201e07:	00 98 02 00 00 00    	add    %bl,0x2(%rax)
  201e0d:	00 00                	add    %al,(%rax)
  201e0f:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 201e15 <_DYNAMIC+0x85>
  201e15:	00 00                	add    %al,(%rax)
  201e17:	00 08                	add    %cl,(%rax)
  201e19:	04 00                	add    $0x0,%al
  201e1b:	00 00                	add    %al,(%rax)
  201e1d:	00 00                	add    %al,(%rax)
  201e1f:	00 06                	add    %al,(%rsi)
  201e21:	00 00                	add    %al,(%rax)
  201e23:	00 00                	add    %al,(%rax)
  201e25:	00 00                	add    %al,(%rax)
  201e27:	00 b8 02 00 00 00    	add    %bh,0x2(%rax)
  201e2d:	00 00                	add    %al,(%rax)
  201e2f:	00 0a                	add    %cl,(%rdx)
  201e31:	00 00                	add    %al,(%rax)
  201e33:	00 00                	add    %al,(%rax)
  201e35:	00 00                	add    %al,(%rax)
  201e37:	00 d0                	add    %dl,%al
  201e39:	00 00                	add    %al,(%rax)
  201e3b:	00 00                	add    %al,(%rax)
  201e3d:	00 00                	add    %al,(%rax)
  201e3f:	00 0b                	add    %cl,(%rbx)
  201e41:	00 00                	add    %al,(%rax)
  201e43:	00 00                	add    %al,(%rax)
  201e45:	00 00                	add    %al,(%rax)
  201e47:	00 18                	add    %bl,(%rax)
  201e49:	00 00                	add    %al,(%rax)
  201e4b:	00 00                	add    %al,(%rax)
  201e4d:	00 00                	add    %al,(%rax)
  201e4f:	00 15 00 00 00 00    	add    %dl,0x0(%rip)        # 201e55 <_DYNAMIC+0xc5>
	...
  201e5d:	00 00                	add    %al,(%rax)
  201e5f:	00 03                	add    %al,(%rbx)
  201e61:	00 00                	add    %al,(%rax)
  201e63:	00 00                	add    %al,(%rax)
  201e65:	00 00                	add    %al,(%rax)
  201e67:	00 80 1f 20 00 00    	add    %al,0x201f(%rax)
  201e6d:	00 00                	add    %al,(%rax)
  201e6f:	00 02                	add    %al,(%rdx)
  201e71:	00 00                	add    %al,(%rax)
  201e73:	00 00                	add    %al,(%rax)
  201e75:	00 00                	add    %al,(%rax)
  201e77:	00 c0                	add    %al,%al
  201e79:	00 00                	add    %al,(%rax)
  201e7b:	00 00                	add    %al,(%rax)
  201e7d:	00 00                	add    %al,(%rax)
  201e7f:	00 14 00             	add    %dl,(%rax,%rax,1)
  201e82:	00 00                	add    %al,(%rax)
  201e84:	00 00                	add    %al,(%rax)
  201e86:	00 00                	add    %al,(%rax)
  201e88:	07                   	(bad)  
  201e89:	00 00                	add    %al,(%rax)
  201e8b:	00 00                	add    %al,(%rax)
  201e8d:	00 00                	add    %al,(%rax)
  201e8f:	00 17                	add    %dl,(%rdi)
  201e91:	00 00                	add    %al,(%rax)
  201e93:	00 00                	add    %al,(%rax)
  201e95:	00 00                	add    %al,(%rax)
  201e97:	00 f8                	add    %bh,%al
  201e99:	05 00 00 00 00       	add    $0x0,%eax
  201e9e:	00 00                	add    %al,(%rax)
  201ea0:	07                   	(bad)  
  201ea1:	00 00                	add    %al,(%rax)
  201ea3:	00 00                	add    %al,(%rax)
  201ea5:	00 00                	add    %al,(%rax)
  201ea7:	00 38                	add    %bh,(%rax)
  201ea9:	05 00 00 00 00       	add    $0x0,%eax
  201eae:	00 00                	add    %al,(%rax)
  201eb0:	08 00                	or     %al,(%rax)
  201eb2:	00 00                	add    %al,(%rax)
  201eb4:	00 00                	add    %al,(%rax)
  201eb6:	00 00                	add    %al,(%rax)
  201eb8:	c0 00 00             	rolb   $0x0,(%rax)
  201ebb:	00 00                	add    %al,(%rax)
  201ebd:	00 00                	add    %al,(%rax)
  201ebf:	00 09                	add    %cl,(%rcx)
  201ec1:	00 00                	add    %al,(%rax)
  201ec3:	00 00                	add    %al,(%rax)
  201ec5:	00 00                	add    %al,(%rax)
  201ec7:	00 18                	add    %bl,(%rax)
  201ec9:	00 00                	add    %al,(%rax)
  201ecb:	00 00                	add    %al,(%rax)
  201ecd:	00 00                	add    %al,(%rax)
  201ecf:	00 1e                	add    %bl,(%rsi)
  201ed1:	00 00                	add    %al,(%rax)
  201ed3:	00 00                	add    %al,(%rax)
  201ed5:	00 00                	add    %al,(%rax)
  201ed7:	00 08                	add    %cl,(%rax)
  201ed9:	00 00                	add    %al,(%rax)
  201edb:	00 00                	add    %al,(%rax)
  201edd:	00 00                	add    %al,(%rax)
  201edf:	00 fb                	add    %bh,%bl
  201ee1:	ff                   	(bad)  
  201ee2:	ff 6f 00             	ljmp   *0x0(%rdi)
  201ee5:	00 00                	add    %al,(%rax)
  201ee7:	00 01                	add    %al,(%rcx)
  201ee9:	00 00                	add    %al,(%rax)
  201eeb:	08 00                	or     %al,(%rax)
  201eed:	00 00                	add    %al,(%rax)
  201eef:	00 fe                	add    %bh,%dh
  201ef1:	ff                   	(bad)  
  201ef2:	ff 6f 00             	ljmp   *0x0(%rdi)
  201ef5:	00 00                	add    %al,(%rax)
  201ef7:	00 f8                	add    %bh,%al
  201ef9:	04 00                	add    $0x0,%al
  201efb:	00 00                	add    %al,(%rax)
  201efd:	00 00                	add    %al,(%rax)
  201eff:	00 ff                	add    %bh,%bh
  201f01:	ff                   	(bad)  
  201f02:	ff 6f 00             	ljmp   *0x0(%rdi)
  201f05:	00 00                	add    %al,(%rax)
  201f07:	00 01                	add    %al,(%rcx)
  201f09:	00 00                	add    %al,(%rax)
  201f0b:	00 00                	add    %al,(%rax)
  201f0d:	00 00                	add    %al,(%rax)
  201f0f:	00 f0                	add    %dh,%al
  201f11:	ff                   	(bad)  
  201f12:	ff 6f 00             	ljmp   *0x0(%rdi)
  201f15:	00 00                	add    %al,(%rax)
  201f17:	00 d8                	add    %bl,%al
  201f19:	04 00                	add    $0x0,%al
  201f1b:	00 00                	add    %al,(%rax)
  201f1d:	00 00                	add    %al,(%rax)
  201f1f:	00 f9                	add    %bh,%cl
  201f21:	ff                   	(bad)  
  201f22:	ff 6f 00             	ljmp   *0x0(%rdi)
  201f25:	00 00                	add    %al,(%rax)
  201f27:	00 03                	add    %al,(%rbx)
	...

Disassembly of section .got:

0000000000201f80 <_GLOBAL_OFFSET_TABLE_>:
  201f80:	90                   	nop
  201f81:	1d 20 00 00 00       	sbb    $0x20,%eax
	...
  201f96:	00 00                	add    %al,(%rax)
  201f98:	e6 06                	out    %al,$0x6
  201f9a:	00 00                	add    %al,(%rax)
  201f9c:	00 00                	add    %al,(%rax)
  201f9e:	00 00                	add    %al,(%rax)
  201fa0:	f6 06 00             	testb  $0x0,(%rsi)
  201fa3:	00 00                	add    %al,(%rax)
  201fa5:	00 00                	add    %al,(%rax)
  201fa7:	00 06                	add    %al,(%rsi)
  201fa9:	07                   	(bad)  
  201faa:	00 00                	add    %al,(%rax)
  201fac:	00 00                	add    %al,(%rax)
  201fae:	00 00                	add    %al,(%rax)
  201fb0:	16                   	(bad)  
  201fb1:	07                   	(bad)  
  201fb2:	00 00                	add    %al,(%rax)
  201fb4:	00 00                	add    %al,(%rax)
  201fb6:	00 00                	add    %al,(%rax)
  201fb8:	26 07                	es (bad) 
  201fba:	00 00                	add    %al,(%rax)
  201fbc:	00 00                	add    %al,(%rax)
  201fbe:	00 00                	add    %al,(%rax)
  201fc0:	36 07                	ss (bad) 
  201fc2:	00 00                	add    %al,(%rax)
  201fc4:	00 00                	add    %al,(%rax)
  201fc6:	00 00                	add    %al,(%rax)
  201fc8:	46 07                	rex.RX (bad) 
  201fca:	00 00                	add    %al,(%rax)
  201fcc:	00 00                	add    %al,(%rax)
  201fce:	00 00                	add    %al,(%rax)
  201fd0:	56                   	push   %rsi
  201fd1:	07                   	(bad)  
	...

Disassembly of section .data:

0000000000202000 <__data_start>:
	...

0000000000202008 <__dso_handle>:
  202008:	08 20                	or     %ah,(%rax)
  20200a:	20 00                	and    %al,(%rax)
  20200c:	00 00                	add    %al,(%rax)
	...

Disassembly of section .bss:

0000000000202010 <__bss_start>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 62             	sub    %dl,0x62(%rbp)
   8:	75 6e                	jne    78 <_init-0x640>
   a:	74 75                	je     81 <_init-0x637>
   c:	20 37                	and    %dh,(%rdi)
   e:	2e 35 2e 30 2d 33    	cs xor $0x332d302e,%eax
  14:	75 62                	jne    78 <_init-0x640>
  16:	75 6e                	jne    86 <_init-0x632>
  18:	74 75                	je     8f <_init-0x629>
  1a:	31 7e 31             	xor    %edi,0x31(%rsi)
  1d:	38 2e                	cmp    %ch,(%rsi)
  1f:	30 34 29             	xor    %dh,(%rcx,%rbp,1)
  22:	20 37                	and    %dh,(%rdi)
  24:	2e                   	cs
  25:	35                   	.byte 0x35
  26:	2e 30 00             	xor    %al,%cs:(%rax)
