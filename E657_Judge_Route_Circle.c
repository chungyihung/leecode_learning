/* Move to origin means #U == #D and #R == #L */
bool judgeCircle(char* moves) {
    unsigned int vert = 0;
    unsigned int hori = 0;
    while( *moves != '\0' ) {
        switch( *moves ) {
            case 'U':
                vert++;
                break;
            case 'D':
                vert--;
                break;
            case 'R':
                hori++;
                break;
            case 'L':
                hori--;
                break;
            default:
                break;
        }
        moves++;
    }
    return (vert == 0 && hori == 0);
}
