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
    var sSz = [ "unknown", "miguelangel", "vara", "professor", "graham", "drawn", "sand", "go", "hand-in-hand", "either", "neutral", "hostile", "manner", "growth", "field", "discovered", "allowed", "residence", "overall", "collective", "debate", "validity", "clashes", "within", "walls", "moment", "steady", "progression", "toward", "joining", "forces", "ethics", "surround", "three", "topics", "fought", "specifically", "entities", "masses", "great", "deal", "faith-based", "understandings", "effect", "tested", "various", "wallace", "mendel", "etc", "readjustment", "understood", "thing", "debates", "correct", "exactly", "stars", "accordance", "fourth-century", "bc", "aristotle", "begun", "explaining", "sun", "existed", "series", "concentric", "spheres", "revolved", "early", "somewhat", "solidified", "works", "later", "came", "down", "scholars", "india", "edison", "took", "credit", "circles", "liked", "catholic", "wholeheartedly", "aristotles", "human-centric", "galilei", "worked", "backup", "proving", "logic", "math", "luckily", "instead", "death", "house-arrest", "remainder", "control", "movement", "western", "john", "ray", "major", "know", "today", "research", "multitudes", "organic", "categorized", "creating", "reproductively", "isolatedeopa", "calling", "isolated", "above", "genus", "post-ray", "carolus", "linnaeus", "invented", "classes", "plants", "alike", "also", "order", "categories", "foundation", "taxonomy", "frowned", "place", "kingdom", "removed", "bit", "once", "homo", "sapiens", "features", "mammals", "georges-louis", "leclerc", "about", "diversity", "cover", "formed", "erasmus", "popularized", "poems", "finally", "adjustment", "pondered", "recorded", "jean-baptiste", "theorized", "adapt", "lose", "parts", "specified", "needed", "otherwise", "use-disuse", "efforts", "mostly", "development", "reading", "paper", "produced", "fence", "public", "hard", "accepting", "darwins", "alfred", "russel", "wallaces", "discovery", "hit", "headlines", "issue", "descendants", "creatures", "struggle", "belief", "inherit", "masters", "claim", "contradicts", "bible", "institution", "represents", "religion", "fighting", "ideas", "join", "suit", "aid", "seen", "threats", "beliefs", "tumults", "meant", "monkeys", "confused", "misconception", "nonetheless", "period", "complex", "against", "renes", "descartes", "paved", "cannot", "reason", "pain", "philosopher", "infamous", "quote", "think", "am", "allow", "room", "ponderance", "possessed", "philosophical", "package", "floating", "back", "ones", "imposed", "articles", "containing", "process", "presented", "implicitly", "explicitly", "maybe", "already-preconceived", "notions", "already", "instilled", "beforehand", "extremely", "difficult", "share", "brute", "whom", "lacks", "emotional", "drive", "along", "scarcity", "meaning", "enough", "push", "away", "wanting", "reserved", "used", "isolate", "agree", "decisions", "modern", "dispute", "coincide", "continuously", "murder", "species-based", "field-mice", "smell", "urine", "mouse", "father", "geese", "support", "herself", "case", "consciously", "whose", "committed", "accounted", "triggered", "females", "brain", "her", "aspect", "left", "openly", "morality", "underrated", "big", "directly", "affected", "nothing", "new", "explored", "lyell", "pointed", "nature", "tendency", "populations", "amount", "food", "water", "remains", "relatively", "held", "check", "resource", "availabilityeopa", "ways", "keep", "environmental", "destruction", "all", "pollution", "excess", "production", "topic", "fears", "dichotomy", "claimed-scientific", "less", "available", "expected", "unnatural", "ending", "preventing", "lead", "atrocious", "basis", "worry", "negative", "get", "trigger", "word", "concern", "different", "alone", "improve", "touches", "modern-day-matter", "answer", "everyone", "culturally", "headed", "direction", "choosing", "own", "preconception", "members", "scientifically-claimed-community", "genitalia", "obtained", "problem", "pertain", "androgen", "insensitivity", "syndrome", "accounts", "approximately", "peoplecrocetti", "wolffian", "structures", "gonads", "internally", "while", "secondary", "characteristics", "develop", "externally", "per", "binary", "easily", "strange", "role", "separate", "dysphoriacrocetti", "route", "peoples", "mental", "issues", "recently", "moved", "point", "considers", "expressing", "oneself", "shackles", "cisgendered", "social", "scrimmage", "publicized", "political", "problems", "loosely", "altered", "able", "feeling", "assigned", "actual", "physiologically", "adjust", "occurring", "effort", "currently", "construction", "far", "soon", "statement", "making", "arguments", "main", "spectrum", "extreme", "extrapolation", "creation", "snowflakes", "heartless", "confine", "forcing", "sign", "wasnt", "individual", "through", "chances", "ran", "random", "said", "stuck", "condition", "changes", "isnt", "anyone", "determine", "how", "time-period", "servants", "often", "owe", "roster", "sold", "ruled", "north", "america", "african", "american", "owed", "slave-owners", "country", "sending", "got", "supplies", "return", "desire", "children", "irish", "decent", "alongside", "black", "fast-forwarding", "modern-", "repayment", "dont", "say", "suffering", "means", "shows", "reproduce", "regardless", "colour", "evidence", "exists", "wish", "segregation", "reconstruction", "itself", "never", "completely", "stagnant", "outside", "continue", "need", "if", "plan", "survive", "rest", "taking", "forward", "obvious", "attempt", "working", "teamwork", "collective-thought", "black-and-white", "tumultuous", "times", "references", "cited", "n.d", "chapter", "rene", "decartes", "retrieved", "april", "http", "www.animalethics.org.uk", "descartes.html", "crocetti", "d", "hormones", "m", "ah-king", "ed", "challenging", "popular", "myths", "biologypp", "-", "switzerland", "springer", "international", "jurmain", "r", "kilgore", "l", "trevathan", "w", "bartelink", "e", "j", "essentials", "physical", "australia", "cengage", "learning", "anthropology", "line", "renaissance", "into", "majority", "mind", "singular", "slow", "community", "greatly", "years", "until", "followed", "cause", "speculation", "throughout", "darwin", "universe", "location", "planets", "around", "teaching", "center", "albeit", "taught", "society", "challenged", "out", "intellectual", "again", "during", "heavy", "world", "whole", "towards", "increase", "types", "fertile", "offspring", "class", "them", "specific", "combination", "became", "form", "then", "written", "stating", "impact", "environment", "dynamic", "lamarck", "gain", "despite", "believed", "rather", "beginning", "books", "claims", "scientists", "given", "charles", "work", "natural", "selection", "current", "day", "institutions", "ancestors", "descended", "another", "followers", "causes", "rightfully", "thoughts", "feel", "animalethics", "i", "therefore", "lack", "autonomy", "accept", "sort", "themselves", "person", "instance", "argument", "choice", "action", "ability", "abort", "male", "destroy", "hold", "she", "population", "discussion", "resources", "overpopulation", "sides", "easy", "believe", "prescribed", "determined", "ais", "genitals", "follow", "common", "transgender", "view", "slippery-slope", "two", "unless", "race", "genes", "color", "treated", "next", "step", "together", "should", "its", "concepts", "accepted", "anything", "at", "these", "over", "origin", "existence", "now", "which", "come", "everything", "eopa", "such", "information", "further", "discussed", "very", "put", "scientific", "thinking", "created", "idea", "we", "considered", "group", "added", "well", "upon", "animal", "god", "due", "shared", "without", "concept", "depending", "part", "known", "fixity", "believing", "creature", "beyond", "conservative", "make", "fetus", "child", "when", "chosen", "may", "past", "size", "fear", "birth", "sex", "too", "skin", "slaves", "white", "always", "many", "whether", "side", "body", "even", "earth", "copernicus", "theory", "did", "would", "liberal", "because", "any", "compared", "same", "female", "born", "do", "both", "up", "groups", "pg", "so", "his", "church", "based", "animals", "change", "other", "human", "does", "between", "each", "evolution", "religious", "under", "made", "like", "he", "life", "just", "abortion", "one", "thought", "who", "will", "individuals", "fight", "an", "what", "still", "than", "species", "way", "their", "can", "since", "more", "culture", "has", "been", "humans", "were", "be", "time", "something", "gender", "science", "though", "being", "have", "some", "or", "much", "was", "are", "there", "people", "from", "they", "with", "by", "on", "for", "had", "it", "as", "this", "but", "not", "in", "a", "and", "is", "that", "to", "of", "the"], iSz = [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 13, 13, 14, 15, 16, 17, 18, 18, 18, 19, 19, 19, 19, 20, 20, 20, 26, 26, 27, 31, 33, 39, 43, 52, 52, 61, 79, 135] , sPh = [ "between culture ", "between culture and ", "culture and ", "science and ", "science and culture ", "and culture ", "in a ", "of science ", "science since ", "since the ", "the renaissance ", "a majority ", "a majority of ", "a majority of the ", "majority of ", "majority of the ", "have been ", "that are ", "as to whether ", "to whether ", "or not ", "of each ", "anything but ", "at the ", "but there ", "a slow ", "with religious ", "had followed ", "under much ", "speculation and ", "be the ", "the origin ", "the origin of ", "origin of ", "now there ", "was the ", "center of ", "though it ", "copernicus had ", "copernicus had challenged ", "had challenged ", "much of ", "was not ", "very much ", "since they ", "they had ", "since it ", "of being ", "put on ", "of his ", "during this ", "during this time ", "this time ", "as a whole ", "a whole ", "was a ", "had created ", "of species ", "fertile offspring ", "species and ", "species and the ", "as they ", "thought to ", "the way ", "the concept ", "one of ", "that animals ", "of their ", "depending on whether ", "on whether ", "known as ", "rather than ", "than evolution ", "made by ", "by charles ", "religious institutions ", "that humans ", "to that ", "to that of ", "that of ", "to have ", "descended from ", "from another ", "followers of ", "conservative religious ", "conservative religious individuals ", "religious individuals ", "but it ", "that time ", "to make ", "with this ", "sort of ", "to an ", "is not something ", "is not something that ", "is not something that is ", "not something ", "not something that ", "not something that is ", "something that is ", "is just ", "for instance ", "a more ", "abortion is ", "have the ", "have the ability ", "have the ability to ", "the ability ", "the ability to ", "ability to ", "to abort ", "other than ", "the child ", "chosen by the ", "the human ", "the scientific ", "as much ", "part of ", "but the ", "as well ", "sides of ", "individuals fear ", "fear that ", "fight for ", "can be ", "for much ", "an easy ", "gender based ", "gender based on ", "believe that ", "that gender ", "prescribed from ", "prescribed from birth ", "from birth ", "that it ", "is known ", "to follow ", "in the past ", "the past ", "to change ", "as though ", "one is ", "that this ", "are made ", "the two ", "some on ", "some on the ", "this way ", "this way of ", "is something that ", "but not ", "because the ", "is much ", "is much more ", "the next ", "the next step ", "next step ", "not always ", "there has ", "there has been ", "in what ", "what is ", "there are still ", "are still ", "much like ", "much more ", "did not ", "that we ", "and the ", "the time ", "they were ", "due to ", "due to the ", "depending on ", "people who were ", "who were ", "from the ", "the people ", "believing that ", "beyond the ", "being compared ", "being compared to ", "the same ", "it is something ", "people to ", "it does ", "it does not ", "chosen by ", "this is ", "is still ", "gender is ", "though this ", "the culture ", "do not ", "as to ", "there is a ", "to be ", "by the ", "the church ", "that they ", "with the ", "of this ", "compared to ", "is something ", "that is ", "there is ", "as a ", "that the ", "based on ", "of a ", "people who ", "does not ", "way of ", "has been ", "there are ", "is a ", "it was ", "is not ", "something that ", "on the ", "it is ", "to the ", "in the ", "of the "], iPh = [ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 8, 10, 15] , sS2 = [ ], iS2 = [ ] , sDc = [ ], iDc = [ ] , sD2 = [ ], iD2 = [ ]  ,
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