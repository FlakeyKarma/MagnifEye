function mkBar(doc, xPos, yPos, w, h, id){
    var c = doc.getElementById(id);
    c.width = w;
    c.height = h;
    var ctx = c.getContext("2d");
    ctx.rect(xPos, yPos, w, h);
	ctx.fillStyle = "lightgrey";
    ctx.fill();
    ctx.stroke();
}

function mkRct(doc, xPos, yPos, w, h, id, max, id0){
    var c = doc.getElementById(id);
    c.width = w;
    c.height = h;
    var ctx = c.getContext("2d");
    ctx.rect(xPos, yPos, w, h);
    if(w/max <= 0.25){
        ctx.fillStyle = "green";
    }
    if(w/max > 0.25 && w/max <= 0.50){
        ctx.fillStyle = "yellow";
    }
    if(w/max > 0.50 && w/max <=0.75){
        ctx.fillStyle = "orange";
    }
    if(w/max > 0.75){
        ctx.fillStyle = "red";
    }
    ctx.fill();
    ctx.stroke();
    mkBar(doc, xPos, yPos, max, h, id0);
}


function outP(x) { 
    var sSz = [ "quick", "red", "fox", "hopped", "big", "brown", "log", "alpha.txt", "the"], iSz = [ 1, 1, 1, 1, 1, 1, 1, 1, 2] , sPh = [ ], iPh = [ ] , sS2 = [ ], iS2 = [ ] , sDc = [ ], iDc = [ ] , sD2 = [ ], iD2 = [ ]  ,
    Slst = [sSz, sPh, sS2, sDc, sD2],
    Ilst = [iSz, iPh, iS2, iDc, iD2],
    sP = [], sP0 = [],
    iP = [], iP0 = [],
    lt0 = [],
    lt1 = [],
    lt2 = [],
    lt = [lt0, lt1, lt2],
    ul0 = [],
    canv = [],
    canv0 = [];

    for(var i = 0; i < Slst.length; i++){
        Slst[i].reverse();
        Ilst[i].reverse();
    }

    for(var i = Slst.length - 1; i >= 0; i--){
        for(var j = Slst[i].length - 1; j >= 0; j--){
            canv[j + i * Slst.length] = "";
            canv[j + i * Slst.length] = document.createElement("canvas");
            canv[j + i * Slst.length].id = "canv" + j + i;

            canv0[j + i * Slst.length] = "";
            canv0[j + i * Slst.length] = document.createElement("canvas");
            canv0[j + i * Slst.length].id = "canv0" + j + i;
            
            if(x){                
                iP[j + i * Slst.length] = "";
                iP0[j + i * Slst.length] = "";
                sP[j + i * Slst.length] = "";
                sP0[j + i * Slst.length] = "";
                lt0[j + i * Slst.length] = "";
                lt1[j + i * Slst.length] = "";

                sP[j + i * Slst.length] = document.createElement("p");
                sP0[j + i * Slst.length] = document.createTextNode(Slst[i][j]);
                sP[j + i * Slst.length].appendChild(sP0[j + i * Slst.length]);
                lt0[j + i * Slst.length] = document.createElement("li");
                lt0[j + i * Slst.length].appendChild(sP[j + i * Slst.length]);

                iP[j + i * Slst.length] = document.createElement("p");
                iP0[j + i * Slst.length] = document.createTextNode(Ilst[i][j]);
                iP[j + i * Slst.length].appendChild(iP0[j + i * Slst.length]);
                lt1[j + i * Slst.length] = document.createElement("li");
                lt1[j + i * Slst.length].appendChild(iP[j + i * Slst.length]);
            }            
            lt2[j + i * Slst.length] = document.createElement("li");
            lt2[j + i * Slst.length].appendChild(canv[j + i * Slst.length]);
            lt2[j + i * Slst.length].appendChild(canv0[j + i * Slst.length]);
        }
    }

    if(x){
        for(var i = 0; i < lt.length; i++){
            ul0[i] = "";
            ul0[i] = document.createElement("ol");
            for(var j = 0; j < lt[i].length; j++){
                ul0[i].appendChild(lt[i][j]);

                if(i == 0){
                    ul0[i].setAttribute("padding-top", "20px");
                    document.getElementById("hW").appendChild(ul0[i]);
                }
                if(i == 1){
                    ul0[i].setAttribute("padding-top", "20px");
                    document.getElementById("hW0").appendChild(ul0[i]);
                }
                if(i == 2){
                    ul0[i].setAttribute("style", "list-style:none; margin:0;");
                    document.getElementById("hW1").appendChild(ul0[i]);
                }   
            }
        }
    }
    
    for(var i = 0; i < Slst.length; i++){
        for(var j = 0; j < Slst[i].length; j++){
            /* doc, xPos, yPos, w, h, id*/
            mkRct(document, 0, 0, (Ilst[i][j]/Ilst[i][0]) * (window.innerWidth * 0.20), 10, canv[j + i * Slst.length].id, (window.innerWidth * 0.20), canv0[j + i * Slst.length].id);
        }
    }
}