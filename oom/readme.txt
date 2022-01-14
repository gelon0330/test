step1:
	 gcc -o mem_alloc mem_alloc.c
 
step2:
	docker build -t registry.steam.crcloud.com/rancher/lxx/mem_alloc:v2 .
step3:
 
	kubctl create ns lxx
step4: 
	kubctl apply -f deploy.yaml -n lxx