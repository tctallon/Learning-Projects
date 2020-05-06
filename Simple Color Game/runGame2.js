function runGame(){
    console.log('test1');

    // variables
    let colorlist = ['blue','cyan','magenta'];
        console.log(colorlist);

    const targetcolor = arrayColor(colorlist);
        console.log(targetcolor); 

    let userinput = '';
        console.log(userinput);

    var check = false;
    var count = 0;

   do {
        count++;
        if (count < 1){
            userinput = prompt('Please type in a color from the following list: '+colorlist.join(', '));
        }
        else if (userinput === null){
            alert('The Game Has Ended');
            return;
        }
        else{
            userinput = prompt('Please type in a new color from the following list: '+colorlist.join(', '));
        }

        check = checkValue(colorlist, targetcolor, userinput);
        alert('You have tried '+count+' times.')
    } while(!check);

    document.body.style.background = targetcolor;
    
}

function arrayColor(colorlist){
    console.log('test2');

    const rColor=colorlist[Math.floor(Math.random()*colorlist.length)];
    console.log(rColor);

    return rColor;
    
}

function checkValue(colorlist, targetcolor, userinput){

    let check = false;

    if(userinput === targetcolor){
        console.log('test3');
        alert('Congrats you chose the correct color.');
        check = true;
        console.log('output 1' + check);
    } else if (colorlist.indexOf(userinput) === -1){
        console.log('test4');
        alert('Your input was not valid');
    } else if (userinput > targetcolor){
        console.log('test5');
        alert('Your input is of a greater alphabetical value.');
    } else if(userinput < targetcolor){
        console.log('test6');
        alert('Your input is of a lower alphabetical value.');
    }
    else{
        console.log('test7');
        check = true;
    }
    return check;
}
