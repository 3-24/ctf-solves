// Run this script on https://webhacking.kr/challenge/bonus-14/
function answer(i){
    x = new XMLHttpRequest();
    x.open('GET','https://webhacking.kr/challenge/bonus-14/?m='+i,false);
    x.send(null);
    return x.responseText;
}

s = ""
for (var i=0; i<50; i++){
    s += answer(i);
}
console.log(s); // FLAG{a7981201c48d0ece288afd01ca43c55b}