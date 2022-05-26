0.创建serviceaccount

kubectl  create sa -n lxx example

0.1 在pod内使用serviceaccount，只需要指定ServiceAccount的名称即可


1.role 和rolebinding 要指定命名空间，在命名空间内起作用
kubectl create role role-example -n lxx  --verb=get,list --resource=pods
kubectl create rolebinding rolebindding-example --serviceaccount=lxx:example --role=role-example  -n lxx
进入pod内查看权限

2.clusterrole 和 clusterrolebindding 不需要指定命名空间，在集群范文内起作用
kubectl create clusterrole clusterrole-example  --verb=get,list --resource=pods
kubectl create clusterrolebinding clusterrolebinding-example --clusterrole=clusterrole-example--serviceaccount=lxx:example
进入pod内查看权限

3.pod内如何查看权限：
我们知道pod可以访问service 或者service的clusterIP，K8S在default命名空间内起了一个kubernetes service用来访问apiserver。
serviceAccount在创建的时候默认会生成secret，secret会挂载到容器内，作为容器访问APIserver的凭证


export CURL_CA_BUNDLE=/var/run/secrets/kubernetes.io/serviceaccount/ca.crt
TOKEN=$(cat /var/run/secrets/kubernetes.io/serviceaccount/token)
curl -H "Authorization:Bearer $TOKEN" https://100.64.0.1/api/v1/namespaces/default/pods
curl -H "Authorization:Bearer $TOKEN" https://100.64.0.1/api/v1/namespaces/lxx/pods
