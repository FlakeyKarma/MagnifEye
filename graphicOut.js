function mkBar(doc, xPos, yPos, w, h, id){
    var c = doc.getElementById(id);
    c.width = w;
    console.log(c.width);
    c.height = h;
    var ctx = c.getContext("2d");
    ctx.rect(xPos, yPos, w, h);
	ctx.fillStyle = "white";
    ctx.fill();
    ctx.stroke();
}

function mkRct(doc, xPos, yPos, w, h, id, max, id0){
    var c = doc.getElementById(id);
    c.width = w;
    console.log(c.width);
    c.height = h;
    var ctx = c.getContext("2d");
    ctx.rect(xPos, yPos, w, h);
    if(w <= 50){
        ctx.fillStyle = "green";
    }
    if(w > 50 && w <= 100){
        ctx.fillStyle = "yellow";
    }
    if(w > 100){
        ctx.fillStyle = "red";
    }
    ctx.fill();
    ctx.stroke();
    mkBar(doc, xPos, yPos, max, h, id0);
}


function outP() { 
    var sSz = [ "every", "site", "claims", "believable", "seem", "internet", "filled", "plethora", "groups", "want", "disperse", "ideas", "need", "evaluated", "understand", "will", "build", "destroy", "main", "point", "done", "my", "psychological", "children", "losing", "age", "there", "numerous", "documents", "sites", "choose", "none", "directly", "associated", "journey", "proved", "ride", "piecing", "gave", "clues", "towards", "companions", "mean", "mind", "given", "based", "different", "when", "backed", "concept", "being", "claimed", "mutually", "agreed", "between", "childhood", "isnt", "necessarily", "ic", "adults", "too", "formed", "inside", "heads", "looked", "responded", "various", "stimuli", "journal", "at", "impact", "gender", "birth-order", "finally", "presence", "lives", "all", "ages", "well", "healthy", "effect", "has", "person", "effected", "experience", "clinical", "psychiatrist", "article", "educated", "neither", "credibility", "juxtaposition", "magazine", "entry", "more", "room", "why", "everything", "occurred", "then", "thoroughly", "giving", "examples", "explored", "big", "problem", "made", "meaning", "its", "very", "caught", "modern", "studies", "positives", "negatives", "major", "contributing", "points", "minds", "youth", "connecting", "pieces", "gathered", "puzzle", "presented", "better", "pulled", "regarding", "which", "out", "wouldnt", "completed", "without", "aid", "frankenstein", "now", "those", "wish", "know", "same", "similar", "maybe", "this", "use", "another", "curious", "soul", "foundation", "questions", "individuals", "whether", "true", "also", "essay", "throughout", "topic", "implications", "friends", "were", "together", "paper", "their", "own", "set", "one", "end", "explaining", "friend", "would", "way", "post", "explained", "though", "been", "much", "explain", "back", "up", "for", "answer", "put", "not", "information", "may", "with", "who", "or", "research", "people", "having", "them", "what", "written", "best", "ics", "blog", "further", "can", "sources", "they", "from", "source", "was", "an", "book", "did", "by", "question", "have", "is", "it", "but", "on", "imaginary", "in", "a", "that", "be", "and", "each", "had", "as", "to", "of", "the"], iSz = [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 6, 8, 8, 9, 9, 9, 12, 17, 21, 45] , sPh = [ ], iPh = [ ] , sS2 = [ ], iS2 = [ ] , sDc = [ ], iDc = [ ] , sD2 = [ ], iD2 = [ ]  ,
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
            lt2[j + i * Slst[i].length].appendChild(canv0[j + i * Slst[i].length]);
            
        }
    }
    
    for(var i = 0; i < lt.length; i++){
        ul0[i] = "";
        ul0[i] = document.createElement("ul");
        for(var j = 0; j < lt[i].length; j++){
            ul0[i].appendChild(lt[i][j]);
            ul0[i].setAttribute("style", "list-style:none; margin:0;");

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
    
    for(var i = 0; i < Slst.length; i++){
        for(var j = 0; j < Slst[i].length; j++){
            /* doc, xPos, yPos, w, h, id*/
            console.log();
            mkRct(document, 0, 0, (Ilst[i][j]/Ilst[i][0]) * 400, 10, canv[j + i * Slst.length].id, 400, canv0[j + i * Slst.length].id);
        }
    }    
}