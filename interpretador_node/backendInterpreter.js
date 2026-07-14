import { exec } from 'child_process';
import path from 'path';

const BACKEND_DIR = path.resolve('../backend')
const BACKEND_PATH = path.resolve(BACKEND_DIR, 'main');

/**
 *  @param {string} args 
*/

export const executarBackend = (args) => {
    return new Promise((resolve, reject) => {
        const comando = `${BACKEND_PATH} ${args}`;

        exec(comando, {cwd: BACKEND_DIR}, (error, stdout, stderr) => {
            if (error) {
                try {
                    const errJson = JSON.parse(stdout);
                    return reject({ status: 400, data: errJson});
                } catch {
                    return reject({ status: 500, data: {erro: "Erro interno no motor em C++"}});
                }
            }

            try{
                const dados = JSON.parse(stdout);
                resolve(dados);
            } catch(parseError){
                reject({ status: 500, data: { erro: "O backend C++ não retornou um JSON válido"}})
            }
        })
    })
}