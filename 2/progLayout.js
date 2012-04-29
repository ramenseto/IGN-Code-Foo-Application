/* Progressive Layout by Alessandro Fulciniti
just change the first line */

MakeLayout("container",540,850,1024);

function MakeLayout(id,minr,maxw,maxr){
if(document.getElementById){
    SetWidth(id,minr,maxw,maxr);
    window.onresize=function(){ SetWidth(id,minr,maxw,maxr);}
    }
}

function SetWidth(id,a,b,c){
var w=getBrowserWidth();
if(w==0) return;
var el=document.getElementById(id);
el.style.margin="0 auto";
var d=el.style;
if(w<=a) d.width=a+"px";
else if(w>=c) d.width=b+"px";
else{
    var m=(b-a)/(c-a);
    d.width=parseInt(m*w+a*(1-m))+"px";
    }
}

function getBrowserWidth(){
if (window.innerWidth) return window.innerWidth;
else if (document.documentElement && document.documentElement.clientWidth!=0)
    return document.documentElement.clientWidth;
else if (document.body) return document.body.clientWidth;
return 0;
}