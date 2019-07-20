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

function opn(document, ID){
    var elm = document.querySelectorAll('#' + ID), X, y = document.getElementById(ID + "B"), t = false, LETAry = ['Reg', 'Red', 'Doc'];
    
    for(var i = 0; i < LETAry.length; i++){
        if(LETAry[i] == ID){
            t = true;
        }
    }

    for (var i = 0; i < elm.length; i++) {
        X = elm[i];
        if(X.style.display == "none"){
            X.style.display = "block";
            if(t){
                y.style.backgroundColor = "green";
            }
        } else {
            X.style.display = "none";
            if(t){
                y.style.backgroundColor = "red";
            }
        }
    }
}

function Clicke(x, document) {
    var LETAry, i;
    
    LETAry = ['Reg', 'Red', 'Doc'];
    for (i = 0; i < LETAry.length; i += 1) {
        if (x == LETAry[i]) {
            opn(document, x);
            continue;
        } else {
            opn(document, x);
        }
    }
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
    var X = new XMLHttpRequest(), path = "wrdz.json";
    X.open('GET', path, true);
    X.responseType = 'blob';
    X.onload = function(window) {
        if(this.status == 200){
            var F = new File([this.response], 'temp');
            var FReader = new FileReader();
            FReader.addEventListener('load', function(window){
                var JSs = JSON.parse(FReader.result);
                var sSz = JSs.sSz,
                iSz = JSs.iSz,
                sPh = JSs.sPh,
                iPh = JSs.iPh,
                sS2 = JSs.sS2,
                iS2 = JSs.iS2,
                sDc = JSs.sDc,
                iDc = JSs.iDc,
                sD2 = JSs.sD2,
                iD2 = JSs.iD2,
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
                canv0 = [],
                lnl = 0;
            
                document.getElementById("dropdown").style.display = "none";
                
                document.getElementById("RegB").style.backgroundColor = "green";
                document.getElementById("RedB").style.backgroundColor = "red";
                document.getElementById("DocB").style.backgroundColor = "red";
            
                for(var i = 0; i < Slst.length; i++){
                    Slst[i].reverse();
                    Ilst[i].reverse();
                }
            
                for(var i = 0; i < Slst.length; i++){
                    for(var j = 0; j < Slst[i].length; j++){
                        canv[lnl] = "";
                        canv[lnl] = document.createElement("canvas");
                        canv[lnl].id = "canv" + j + i;
                        
                        canv0[lnl] = "";
                        canv0[lnl] = document.createElement("canvas");
                        canv0[lnl].id = "canv0" + j + i;
                        
						//Just in case
                        //if(x){                
						iP[lnl] = "";
						iP0[lnl] = "";
						sP[lnl] = "";
						sP0[lnl] = "";
						lt0[lnl] = "";
						lt1[lnl] = "";
						
						sP[lnl] = document.createElement("p");
						sP0[lnl] = document.createTextNode(Slst[i][j]);
						sP[lnl].appendChild(sP0[lnl]);
						lt0[lnl] = document.createElement("li");
						lt0[lnl].appendChild(sP[lnl]);
						
						iP[lnl] = document.createElement("p");
						iP0[lnl] = document.createTextNode(Ilst[i][j]);
						iP[lnl].appendChild(iP0[lnl]);
						lt1[lnl] = document.createElement("li");
						lt1[lnl].appendChild(iP[lnl]);
						//Just in case
                        //}            
                        lt2[lnl] = document.createElement("li");
                        lt2[lnl].appendChild(canv[lnl]);
                        lt2[lnl].appendChild(canv0[lnl]);
                        lnl++;
                        if(lnl - 1 < sSz.length){
                            lt0[lnl - 1].id = "Reg";
                            lt1[lnl - 1].id = "Reg";
                            lt2[lnl - 1].id = "Reg";
                            lt0[lnl - 1].style.display = "block";
                            lt1[lnl - 1].style.display = "block";
                            lt2[lnl - 1].style.display = "block";
                            continue;
                        }
                        if(lnl - 1 < sSz.length + sPh.length){
                            lt0[lnl - 1].id = "Red";
                            lt1[lnl - 1].id = "Red";
                            lt2[lnl - 1].id = "Red";
                            lt0[lnl - 1].style.display = "none";
                            lt1[lnl - 1].style.display = "none";
                            lt2[lnl - 1].style.display = "none";
                            continue;
                        } else {
                            lt0[lnl - 1].id = "Doc";
                            lt1[lnl - 1].id = "Doc";
                            lt2[lnl - 1].id = "Doc";
                            lt0[lnl - 1].style.display = "none";
                            lt1[lnl - 1].style.display = "none";
                            lt2[lnl - 1].style.display = "none";
                        }
                    }
                }
            
                for(var i = 0; i < lt.length; i++){
                    for(var j = 0; j < lt[i].length; j++){
                        console.log(lt[i][j]);
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
            
                lnl = 0;
            
                for(var i = 0; i < Slst.length; i++){
                    for(var j = 0; j < Slst[i].length; j++){
                        /* doc, xPos, yPos, w, h, id*/
                        mkRct(document, 0, 0, (Ilst[i][j]/Ilst[i][0]) * (innerWidth * 0.20), 10, canv[lnl].id, (innerWidth * 0.20), canv0[lnl].id);
                        lnl++;
                    }
                }
            });
            FReader.readAsText(F);
        }
    }
    X.send();
}