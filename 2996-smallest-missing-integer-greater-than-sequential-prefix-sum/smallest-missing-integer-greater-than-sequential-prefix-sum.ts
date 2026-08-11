function missingInteger(nums: number[]): number {
    const n = nums.length;
    const st:Set<number>=new Set(nums);
    let sum =nums[0];
    for(let i=1;i<n;i++){
        if(nums[i]===nums[i-1]+1){
            sum+=nums[i];
        }
        else{
            break;
        }
    }
    while(st.has(sum)){
        sum++;
    }
    return sum;
};