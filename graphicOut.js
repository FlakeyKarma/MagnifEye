function mkRct(doc, xPos, yPos, w, h, id){
    var c = doc.getElementById(id);
    c.width = w;
    c.height = h;
    var ctx = c.getContext("2d");
    ctx.rect(xPos, yPos, w, h);
    if(w <= 5){
        ctx.fillStyle = "green";
    }
    if(w > 5 && w <= 10){
        ctx.fillStyle = "yellow";
    }
    if(w > 10){
        ctx.fillStyle = "red";
    }
    ctx.fill();
    ctx.stroke();
}

function outP() { 
    var sSz = [ "end", "non", "qui", "et", "aliqua", "dolore", "veniam", "est", "nostrud", "eiusmod", "sed", "desert", "ipsum", "amet", "ut", "sunt", "anim", "adipiscing", "incididunt", "ad"], iSz = [ 1, 309, 311, 319, 321, 323, 325, 328, 330, 331, 332, 334, 335, 338, 346, 347, 358, 361, 364, 368] , sPh = [ ], iPh = [ ] , sS2 = [ ], iS2 = [ ] , sDc = [ ], iDc = [ ] , sD2 = [ ], iD2 = [ ]  ,
	Slst = [sSz, sPh, sS2, sDc, sD2],
    Ilst = [iSz, iPh, iS2, iDc, iD2],
    sP = [], sP0 = [],
    iP = [], iP0 = [],
    lt0 = [],
    lt1 = [],
    lt2 = [],
    lt = [lt0, lt1, lt2],
    ul0 = [],
    canv = [];

    for(var i = 0; i < Slst.length; i++){
        for(var j = 0; j < Slst[i].length; j++){
            canv[j + i * Slst.length] = "";
            canv[j + i * Slst.length] = document.createElement("canvas");
            canv[j + i * Slst.length].id = "canv" + j + i;
            
            iP[j + i * Slst.length] = "";
            iP0[j + i * Slst.length] = "";
            sP[j + i * Slst.length] = "";
            sP0[j + i * Slst.length] = "";
            lt0[j + i * Slst.length] = "";
            lt1[j + i * Slst.length] = "";
            
            sP[j + i * Slst[i].length] = document.createElement("p");
            sP0[j + i * Slst[i].length] = document.createTextNode(Slst[i][j]);
            sP[j + i * Slst[i].length].appendChild(sP0[j + i * Slst[i].length]);
            lt0[j + i * Slst[i].length] = document.createElement("li");
            lt0[j + i * Slst[i].length].appendChild(sP[j + i * Slst[i].length]);

            iP[j + i * Slst[i].length] = document.createElement("p");
            iP0[j + i * Slst[i].length] = document.createTextNode(Ilst[i][j]);
            iP[j + i * Slst[i].length].appendChild(iP0[j + i * Slst[i].length]);
            lt1[j + i * Slst[i].length] = document.createElement("li");
            lt1[j + i * Slst[i].length].appendChild(iP[j + i * Slst[i].length]);
            lt2[j + i * Slst[i].length] = document.createElement("li");
            lt2[j + i * Slst[i].length].appendChild(canv[j + i * Slst[i].length]);
        }
    }
    
    for(var i = 0; i < lt.length; i++){
        for(var j = 0; j < lt[i].length; j++){
            ul0[j + i * lt.length] = "";
            ul0[j + i * lt.length] = document.createElement("ul");
            ul0[j + i * lt.length].appendChild(lt[i][j]);
            if(i == 0){
                document.getElementById("hW").appendChild(ul0[j + i * lt.length]);
            }
            if(i == 1){
                ul0[j + i * lt.length].setAttribute("style", "list-style:none;");
                document.getElementById("hW0").appendChild(ul0[j + i * lt.length]);
            }
            if(i == 2){
                ul0[j + i * lt.length].setAttribute("style", "list-style:none;");
                document.getElementById("hW1").appendChild(ul0[j + i * lt.length]);
            }   
        }
    }
    
    for(var i = 0; i < Slst.length; i++){
        for(var j = 0; j < Slst[i].length; j++){
            /* doc, xPos, yPos, w, h, id*/
            mkRct(document, 0, 0, Ilst[i][j], 10, canv[j + i * Slst.length].id);
        }
    }
}