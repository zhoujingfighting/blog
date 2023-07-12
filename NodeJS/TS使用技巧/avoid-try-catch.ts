const error = async (para: boolean) :Promise<string>  => {
    if(para)
        return Promise.resolve("Very good");
    throw new Error("This is test");
} 

const test =async () => {
    const err = await error(false).catch(error => {
        console.log(error.message)
    })
}
const test1 =async () => {
    const err = await error(true).catch(error => {
        console.log(error.message)
    })
    if (err) {
        console.log(err)  
    }
}
test()
test1()