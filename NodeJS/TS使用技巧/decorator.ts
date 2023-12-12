function log(target: any, propertyKey: string, descriptor: PropertyDescriptor) {
    // Capture the functional behavior of the decorated method
    const originalMethod = descriptor.value;
    // Override the decorated method's behavior with new behavior
    descriptor.value = function (...args: any[]) {
        let msg: string;
        // The decorated method's parameters will be passed in as args.
        // We'll assume the decorated method might only have a single parameter,
        // check to see if it's been passed in the method
        if (args[0]) {
            msg = (`${propertyKey}, that has a parameter value: ${args[0]}`)
        }
        else {
            msg = `${propertyKey}`
        }
        // Emit a message to the console
        console.log(`Logger says - calling the method: ${msg}`);
        // Execute the behavior originally programmed in
        // the decorated method
        const result = originalMethod.apply(this, args);
        // if the decorated method returned a value when executed,
        // capture that result
        if (result) {
            msg = `${propertyKey} and returned: ${JSON.stringify(result)}`;
        }
        else {
            msg = `${propertyKey}`;
        }
        // Having executed the decorated method's behavior, emit
        // a message to the console report what happened
        console.log(`Logger says - called the method: ${msg}`);
        return result;
    };
    return descriptor;
};
// To learn more about the language, click above in "Examples" or "What's New".
// Otherwise, get started by removing these comments and the world is your playground.


class Printer {
    @log
    print(msg: string): any {
        // console.log(`Printer class is printing ${msg}`);
    }
}

const p = new Printer();
p.print("grgrg");